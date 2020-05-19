/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00008.H $         */
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

#ifndef __PERV_REG00008_H_
#define __PERV_REG00008_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT14_ARY]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_RW]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_RW]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_RW]


//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC,
           FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC,
           FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC,
           FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW]


//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5]

//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5]

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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT]

//>> PREP_[MCAST_GRP_0_SLAVES_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCAST_GRP_0_SLAVES_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCAST_GRP_0_SLAVES_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCAST_GRP_0_SLAVES_REG]

//>> GET_[MCAST_GRP_0_SLAVES_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCAST_GRP_0_SLAVES_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCAST_GRP_0_SLAVES_REG;
#endif
    return fapi2::getScom(i_target, MCAST_GRP_0_SLAVES_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCAST_GRP_0_SLAVES_REG]

//>> PUT_[MCAST_GRP_0_SLAVES_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCAST_GRP_0_SLAVES_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCAST_GRP_0_SLAVES_REG));
#endif
    return fapi2::putScom(i_target, MCAST_GRP_0_SLAVES_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCAST_GRP_0_SLAVES_REG]


//>> SET_[MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0]
static inline fapi2::buffer<uint64_t>& SET_MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCAST_GRP_0_SLAVES_REG));
#endif
    return o_data.insertFromRight<MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0,
           MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0]

//>> SET_[MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0]
static inline fapi2::buffer<uint64_t>& SET_MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCAST_GRP_0_SLAVES_REG));
#endif
    return o_data.insertFromRight<MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0,
           MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0]

//>> GET_[MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0]
static inline fapi2::buffer<uint64_t>& GET_MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCAST_GRP_0_SLAVES_REG));
#endif
    return i_data.extractToRight<MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0,
           MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL1_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL1_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL1_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL1_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL1_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL1_FSI, FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL1_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE]

//>> PREP_[REC_ERR_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REC_ERR_REG2]

//>> GET_[REC_ERR_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_REG2;
#endif
    return fapi2::getScom(i_target, REC_ERR_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REC_ERR_REG2]

//>> PUT_[REC_ERR_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_REG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return fapi2::putScom(i_target, REC_ERR_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REC_ERR_REG2]


//>> SET_[REC_ERR_REG2_32_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_32_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_32_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_32_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_32_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_32_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_32_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_32_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_32_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_32_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_32_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_32_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_32_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_32_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_32_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_32_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_32_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_32_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_32_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_32_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_32_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_32_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_32_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_32_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_32_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_32_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_32_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_32_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_32_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_32_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_32_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_32_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_32_ERROR_CODE,
           REC_ERR_REG2_32_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_32_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_32_ERROR_CODE]

//>> SET_[REC_ERR_REG2_32_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_32_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_32_ERROR_CODE,
           REC_ERR_REG2_32_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_32_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_32_ERROR_CODE]

//>> GET_[REC_ERR_REG2_32_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_32_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_32_ERROR_CODE,
           REC_ERR_REG2_32_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_32_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_32_ERROR_CODE]

//>> SET_[REC_ERR_REG2_33_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_33_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_33_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_33_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_33_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_33_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_33_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_33_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_33_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_33_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_33_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_33_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_33_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_33_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_33_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_33_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_33_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_33_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_33_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_33_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_33_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_33_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_33_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_33_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_33_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_33_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_33_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_33_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_33_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_33_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_33_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_33_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_33_ERROR_CODE,
           REC_ERR_REG2_33_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_33_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_33_ERROR_CODE]

//>> SET_[REC_ERR_REG2_33_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_33_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_33_ERROR_CODE,
           REC_ERR_REG2_33_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_33_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_33_ERROR_CODE]

//>> GET_[REC_ERR_REG2_33_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_33_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_33_ERROR_CODE,
           REC_ERR_REG2_33_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_33_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_33_ERROR_CODE]

//>> SET_[REC_ERR_REG2_34_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_34_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_34_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_34_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_34_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_34_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_34_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_34_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_34_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_34_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_34_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_34_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_34_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_34_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_34_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_34_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_34_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_34_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_34_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_34_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_34_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_34_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_34_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_34_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_34_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_34_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_34_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_34_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_34_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_34_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_34_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_34_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_34_ERROR_CODE,
           REC_ERR_REG2_34_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_34_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_34_ERROR_CODE]

//>> SET_[REC_ERR_REG2_34_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_34_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_34_ERROR_CODE,
           REC_ERR_REG2_34_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_34_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_34_ERROR_CODE]

//>> GET_[REC_ERR_REG2_34_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_34_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_34_ERROR_CODE,
           REC_ERR_REG2_34_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_34_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_34_ERROR_CODE]

//>> SET_[REC_ERR_REG2_35_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_35_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_35_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_35_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_35_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_35_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_35_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_35_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_35_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_35_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_35_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_35_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_35_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_35_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_35_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_35_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_35_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_35_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_35_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_35_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_35_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_35_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_35_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_35_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_35_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_35_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_35_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_35_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_35_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_35_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_35_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_35_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_35_ERROR_CODE,
           REC_ERR_REG2_35_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_35_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_35_ERROR_CODE]

//>> SET_[REC_ERR_REG2_35_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_35_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_35_ERROR_CODE,
           REC_ERR_REG2_35_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_35_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_35_ERROR_CODE]

//>> GET_[REC_ERR_REG2_35_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_35_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_35_ERROR_CODE,
           REC_ERR_REG2_35_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_35_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_35_ERROR_CODE]

//>> SET_[REC_ERR_REG2_36_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_36_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_36_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_36_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_36_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_36_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_36_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_36_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_36_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_36_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_36_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_36_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_36_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_36_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_36_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_36_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_36_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_36_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_36_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_36_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_36_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_36_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_36_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_36_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_36_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_36_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_36_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_36_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_36_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_36_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_36_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_36_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_36_ERROR_CODE,
           REC_ERR_REG2_36_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_36_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_36_ERROR_CODE]

//>> SET_[REC_ERR_REG2_36_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_36_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_36_ERROR_CODE,
           REC_ERR_REG2_36_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_36_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_36_ERROR_CODE]

//>> GET_[REC_ERR_REG2_36_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_36_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_36_ERROR_CODE,
           REC_ERR_REG2_36_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_36_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_36_ERROR_CODE]

//>> SET_[REC_ERR_REG2_37_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_37_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_37_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_37_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_37_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_37_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_37_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_37_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_37_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_37_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_37_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_37_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_37_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_37_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_37_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_37_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_37_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_37_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_37_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_37_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_37_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_37_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_37_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_37_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_37_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_37_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_37_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_37_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_37_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_37_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_37_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_37_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_37_ERROR_CODE,
           REC_ERR_REG2_37_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_37_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_37_ERROR_CODE]

//>> SET_[REC_ERR_REG2_37_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_37_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_37_ERROR_CODE,
           REC_ERR_REG2_37_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_37_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_37_ERROR_CODE]

//>> GET_[REC_ERR_REG2_37_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_37_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_37_ERROR_CODE,
           REC_ERR_REG2_37_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_37_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_37_ERROR_CODE]

//>> SET_[REC_ERR_REG2_38_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_38_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_38_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_38_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_38_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_38_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_38_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_38_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_38_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_38_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_38_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_38_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_38_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_38_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_38_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_38_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_38_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_38_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_38_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_38_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_38_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_38_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_38_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_38_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_38_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_38_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_38_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_38_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_38_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_38_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_38_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_38_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_38_ERROR_CODE,
           REC_ERR_REG2_38_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_38_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_38_ERROR_CODE]

//>> SET_[REC_ERR_REG2_38_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_38_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_38_ERROR_CODE,
           REC_ERR_REG2_38_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_38_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_38_ERROR_CODE]

//>> GET_[REC_ERR_REG2_38_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_38_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_38_ERROR_CODE,
           REC_ERR_REG2_38_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_38_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_38_ERROR_CODE]

//>> SET_[REC_ERR_REG2_39_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_39_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_39_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_39_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_39_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_39_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_39_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_39_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_39_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_39_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_39_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_39_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_39_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_39_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_39_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_39_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_39_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_39_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_39_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_39_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_39_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_39_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_39_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_39_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_39_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_39_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_39_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_39_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_39_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_39_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_39_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_39_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_39_ERROR_CODE,
           REC_ERR_REG2_39_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_39_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_39_ERROR_CODE]

//>> SET_[REC_ERR_REG2_39_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_39_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_39_ERROR_CODE,
           REC_ERR_REG2_39_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_39_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_39_ERROR_CODE]

//>> GET_[REC_ERR_REG2_39_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_39_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_39_ERROR_CODE,
           REC_ERR_REG2_39_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_39_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_39_ERROR_CODE]

//>> SET_[REC_ERR_REG2_40_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_40_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_40_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_40_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_40_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_40_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_40_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_40_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_40_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_40_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_40_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_40_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_40_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_40_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_40_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_40_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_40_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_40_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_40_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_40_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_40_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_40_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_40_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_40_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_40_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_40_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_40_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_40_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_40_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_40_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_40_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_40_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_40_ERROR_CODE,
           REC_ERR_REG2_40_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_40_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_40_ERROR_CODE]

//>> SET_[REC_ERR_REG2_40_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_40_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_40_ERROR_CODE,
           REC_ERR_REG2_40_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_40_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_40_ERROR_CODE]

//>> GET_[REC_ERR_REG2_40_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_40_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_40_ERROR_CODE,
           REC_ERR_REG2_40_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_40_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_40_ERROR_CODE]

//>> SET_[REC_ERR_REG2_41_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_41_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_41_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_41_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_41_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_41_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_41_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_41_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_41_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_41_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_41_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_41_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_41_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_41_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_41_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_41_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_41_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_41_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_41_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_41_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_41_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_41_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_41_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_41_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_41_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_41_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_41_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_41_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_41_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_41_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_41_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_41_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_41_ERROR_CODE,
           REC_ERR_REG2_41_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_41_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_41_ERROR_CODE]

//>> SET_[REC_ERR_REG2_41_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_41_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_41_ERROR_CODE,
           REC_ERR_REG2_41_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_41_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_41_ERROR_CODE]

//>> GET_[REC_ERR_REG2_41_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_41_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_41_ERROR_CODE,
           REC_ERR_REG2_41_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_41_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_41_ERROR_CODE]

//>> SET_[REC_ERR_REG2_42_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_42_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_42_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_42_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_42_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_42_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_42_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_42_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_42_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_42_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_42_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_42_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_42_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_42_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_42_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_42_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_42_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_42_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_42_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_42_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_42_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_42_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_42_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_42_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_42_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_42_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_42_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_42_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_42_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_42_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_42_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_42_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_42_ERROR_CODE,
           REC_ERR_REG2_42_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_42_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_42_ERROR_CODE]

//>> SET_[REC_ERR_REG2_42_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_42_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_42_ERROR_CODE,
           REC_ERR_REG2_42_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_42_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_42_ERROR_CODE]

//>> GET_[REC_ERR_REG2_42_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_42_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_42_ERROR_CODE,
           REC_ERR_REG2_42_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_42_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_42_ERROR_CODE]

//>> SET_[REC_ERR_REG2_43_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_43_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_43_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_43_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_43_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_43_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_43_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_43_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_43_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_43_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_43_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_43_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_43_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_43_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_43_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_43_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_43_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_43_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_43_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_43_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_43_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_43_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_43_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_43_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_43_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_43_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_43_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_43_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_43_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_43_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_43_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_43_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_43_ERROR_CODE,
           REC_ERR_REG2_43_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_43_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_43_ERROR_CODE]

//>> SET_[REC_ERR_REG2_43_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_43_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_43_ERROR_CODE,
           REC_ERR_REG2_43_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_43_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_43_ERROR_CODE]

//>> GET_[REC_ERR_REG2_43_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_43_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_43_ERROR_CODE,
           REC_ERR_REG2_43_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_43_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_43_ERROR_CODE]

//>> SET_[REC_ERR_REG2_44_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_44_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_44_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_44_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_44_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_44_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_44_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_44_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_44_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_44_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_44_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_44_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_44_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_44_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_44_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_44_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_44_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_44_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_44_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_44_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_44_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_44_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_44_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_44_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_44_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_44_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_44_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_44_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_44_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_44_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_44_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_44_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_44_ERROR_CODE,
           REC_ERR_REG2_44_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_44_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_44_ERROR_CODE]

//>> SET_[REC_ERR_REG2_44_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_44_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_44_ERROR_CODE,
           REC_ERR_REG2_44_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_44_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_44_ERROR_CODE]

//>> GET_[REC_ERR_REG2_44_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_44_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_44_ERROR_CODE,
           REC_ERR_REG2_44_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_44_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_44_ERROR_CODE]

//>> SET_[REC_ERR_REG2_45_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_45_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_45_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_45_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_45_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_45_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_45_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_45_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_45_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_45_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_45_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_45_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_45_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_45_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_45_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_45_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_45_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_45_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_45_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_45_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_45_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_45_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_45_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_45_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_45_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_45_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_45_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_45_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_45_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_45_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_45_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_45_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_45_ERROR_CODE,
           REC_ERR_REG2_45_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_45_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_45_ERROR_CODE]

//>> SET_[REC_ERR_REG2_45_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_45_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_45_ERROR_CODE,
           REC_ERR_REG2_45_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_45_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_45_ERROR_CODE]

//>> GET_[REC_ERR_REG2_45_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_45_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_45_ERROR_CODE,
           REC_ERR_REG2_45_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_45_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_45_ERROR_CODE]

//>> SET_[REC_ERR_REG2_46_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_46_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_46_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_46_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_46_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_46_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_46_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_46_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_46_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_46_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_46_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_46_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_46_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_46_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_46_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_46_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_46_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_46_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_46_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_46_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_46_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_46_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_46_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_46_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_46_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_46_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_46_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_46_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_46_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_46_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_46_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_46_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_46_ERROR_CODE,
           REC_ERR_REG2_46_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_46_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_46_ERROR_CODE]

//>> SET_[REC_ERR_REG2_46_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_46_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_46_ERROR_CODE,
           REC_ERR_REG2_46_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_46_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_46_ERROR_CODE]

//>> GET_[REC_ERR_REG2_46_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_46_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_46_ERROR_CODE,
           REC_ERR_REG2_46_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_46_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_46_ERROR_CODE]

//>> SET_[REC_ERR_REG2_47_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_47_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_47_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_47_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_47_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_47_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_47_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_47_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_47_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_47_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_47_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_47_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.setBit<REC_ERR_REG2_47_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_REG2_47_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_47_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_REG2_47_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_REG2_47_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.clearBit<REC_ERR_REG2_47_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_REG2_47_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_REG2_47_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_47_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_47_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_47_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_47_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_47_RESPONSE_BIT]

//>> GET_[REC_ERR_REG2_47_RESPONSE_BIT]
static inline bool GET_REC_ERR_REG2_47_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.getBit<REC_ERR_REG2_47_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_REG2_47_RESPONSE_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_47_RESPONSE_BIT]

//>> SET_[REC_ERR_REG2_47_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_47_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_47_ERROR_CODE,
           REC_ERR_REG2_47_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_REG2_47_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_47_ERROR_CODE]

//>> SET_[REC_ERR_REG2_47_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_REG2_47_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_REG2_47_ERROR_CODE,
           REC_ERR_REG2_47_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_REG2_47_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_REG2_47_ERROR_CODE]

//>> GET_[REC_ERR_REG2_47_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_REG2_47_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_REG2));
#endif
    return i_data.extractToRight<REC_ERR_REG2_47_ERROR_CODE,
           REC_ERR_REG2_47_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_REG2_47_ERROR_CODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_REG2_47_ERROR_CODE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
