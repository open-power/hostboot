/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pauc/reg00004.H $         */
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

#ifndef __PAUC_REG00004_H_
#define __PAUC_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT]

//>> PREP_[PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR]

//>> PUT_[PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR]

//>> PREP_[PHY_PPE_WRAP_ARB_CSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHY_PPE_WRAP_ARB_CSCR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_PPE_WRAP_ARB_CSCR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PHY_PPE_WRAP_ARB_CSCR_WO_OR]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHY_PPE_WRAP_ARB_CSCR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_PPE_WRAP_ARB_CSCR_WO_OR;
#endif
    return fapi2::getScom(i_target, PHY_PPE_WRAP_ARB_CSCR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_WO_OR]

//>> PUT_[PHY_PPE_WRAP_ARB_CSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHY_PPE_WRAP_ARB_CSCR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, PHY_PPE_WRAP_ARB_CSCR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PHY_PPE_WRAP_ARB_CSCR_WO_OR]


//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.setBit<PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]

//>> CLEAR_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.clearBit<PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& GET_PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.extractToRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]
static inline bool GET_PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.getBit<PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.setBit<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]

//>> CLEAR_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.clearBit<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.extractToRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]
static inline bool GET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.getBit<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.setBit<PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]

//>> CLEAR_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.clearBit<PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& GET_PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.extractToRight<PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]
static inline bool GET_PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.getBit<PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.setBit<PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]

//>> CLEAR_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.clearBit<PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& GET_PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.extractToRight<PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]
static inline bool GET_PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.getBit<PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.setBit<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]

//>> CLEAR_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.clearBit<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& GET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.extractToRight<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]
static inline bool GET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.getBit<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.setBit<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]

//>> CLEAR_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.clearBit<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& GET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.extractToRight<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]
static inline bool GET_PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.getBit<PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7,
           PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7,
           PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7]
static inline fapi2::buffer<uint64_t>& GET_PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.extractToRight<PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7,
           PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX,
           PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX]

//>> SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX]
static inline fapi2::buffer<uint64_t>& SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return o_data.insertFromRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX,
           PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX]
static inline fapi2::buffer<uint64_t>& GET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return i_data.extractToRight<PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX,
           PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline bool GET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> PREP_[TRA0_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA0_TR0_TRACE_LO_DATA_REG]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA0_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG]

//>> PUT_[TRA0_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA0_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA0_TR0_TRACE_LO_DATA_REG]


//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline bool GET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline bool GET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> PREP_[PHY_PPE_WRAP_ARB_CSCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHY_PPE_WRAP_ARB_CSCR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_PPE_WRAP_ARB_CSCR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PHY_PPE_WRAP_ARB_CSCR_RW]

//>> GET_[PHY_PPE_WRAP_ARB_CSCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHY_PPE_WRAP_ARB_CSCR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_PPE_WRAP_ARB_CSCR_RW;
#endif
    return fapi2::getScom(i_target, PHY_PPE_WRAP_ARB_CSCR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PHY_PPE_WRAP_ARB_CSCR_RW]

//>> PUT_[PHY_PPE_WRAP_ARB_CSCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHY_PPE_WRAP_ARB_CSCR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHY_PPE_WRAP_ARB_CSCR_RW, PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR, PHY_PPE_WRAP_ARB_CSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, PHY_PPE_WRAP_ARB_CSCR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PHY_PPE_WRAP_ARB_CSCR_RW]

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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_CYCLES]


//>> PREP_[EPS_FIR_LOCAL_ACTION2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_LOCAL_ACTION2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_ACTION2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_FIR_LOCAL_ACTION2]

//>> GET_[EPS_FIR_LOCAL_ACTION2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_LOCAL_ACTION2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_ACTION2;
#endif
    return fapi2::getScom(i_target, EPS_FIR_LOCAL_ACTION2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2]

//>> PUT_[EPS_FIR_LOCAL_ACTION2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_LOCAL_ACTION2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return fapi2::putScom(i_target, EPS_FIR_LOCAL_ACTION2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_FIR_LOCAL_ACTION2]


//>> SET_[EPS_FIR_LOCAL_ACTION2_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_00]

//>> SET_[EPS_FIR_LOCAL_ACTION2_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_00]

//>> SET_[EPS_FIR_LOCAL_ACTION2_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_00]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_00]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_00]

//>> GET_[EPS_FIR_LOCAL_ACTION2_00]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_00]

//>> GET_[EPS_FIR_LOCAL_ACTION2_00]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_00]

//>> SET_[EPS_FIR_LOCAL_ACTION2_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_01]

//>> SET_[EPS_FIR_LOCAL_ACTION2_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_01]

//>> SET_[EPS_FIR_LOCAL_ACTION2_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_01]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_01]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_01]

//>> GET_[EPS_FIR_LOCAL_ACTION2_01]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_01]

//>> GET_[EPS_FIR_LOCAL_ACTION2_01]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_01]

//>> SET_[EPS_FIR_LOCAL_ACTION2_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_02]

//>> SET_[EPS_FIR_LOCAL_ACTION2_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_02]

//>> SET_[EPS_FIR_LOCAL_ACTION2_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_02]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_02]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_02]

//>> GET_[EPS_FIR_LOCAL_ACTION2_02]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_02]

//>> GET_[EPS_FIR_LOCAL_ACTION2_02]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_02]

//>> SET_[EPS_FIR_LOCAL_ACTION2_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_03]

//>> SET_[EPS_FIR_LOCAL_ACTION2_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_03]

//>> SET_[EPS_FIR_LOCAL_ACTION2_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_03]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_03]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_03]

//>> GET_[EPS_FIR_LOCAL_ACTION2_03]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_03]

//>> GET_[EPS_FIR_LOCAL_ACTION2_03]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_03]

//>> SET_[EPS_FIR_LOCAL_ACTION2_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_04]

//>> SET_[EPS_FIR_LOCAL_ACTION2_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_04]

//>> SET_[EPS_FIR_LOCAL_ACTION2_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_04]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_04]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_04]

//>> GET_[EPS_FIR_LOCAL_ACTION2_04]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_04]

//>> GET_[EPS_FIR_LOCAL_ACTION2_04]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_04]

//>> SET_[EPS_FIR_LOCAL_ACTION2_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_05]

//>> SET_[EPS_FIR_LOCAL_ACTION2_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_05]

//>> SET_[EPS_FIR_LOCAL_ACTION2_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_05]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_05]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_05]

//>> GET_[EPS_FIR_LOCAL_ACTION2_05]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_05]

//>> GET_[EPS_FIR_LOCAL_ACTION2_05]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_05]

//>> SET_[EPS_FIR_LOCAL_ACTION2_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_06]

//>> SET_[EPS_FIR_LOCAL_ACTION2_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_06]

//>> SET_[EPS_FIR_LOCAL_ACTION2_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_06]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_06]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_06]

//>> GET_[EPS_FIR_LOCAL_ACTION2_06]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_06]

//>> GET_[EPS_FIR_LOCAL_ACTION2_06]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_06]

//>> SET_[EPS_FIR_LOCAL_ACTION2_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_07]

//>> SET_[EPS_FIR_LOCAL_ACTION2_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_07]

//>> SET_[EPS_FIR_LOCAL_ACTION2_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_07]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_07]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_07]

//>> GET_[EPS_FIR_LOCAL_ACTION2_07]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_07]

//>> GET_[EPS_FIR_LOCAL_ACTION2_07]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_07]

//>> SET_[EPS_FIR_LOCAL_ACTION2_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_08]

//>> SET_[EPS_FIR_LOCAL_ACTION2_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_08]

//>> SET_[EPS_FIR_LOCAL_ACTION2_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_08]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_08]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_08]

//>> GET_[EPS_FIR_LOCAL_ACTION2_08]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_08]

//>> GET_[EPS_FIR_LOCAL_ACTION2_08]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_08]

//>> SET_[EPS_FIR_LOCAL_ACTION2_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_09]

//>> SET_[EPS_FIR_LOCAL_ACTION2_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_09]

//>> SET_[EPS_FIR_LOCAL_ACTION2_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_09]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_09]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_09]

//>> GET_[EPS_FIR_LOCAL_ACTION2_09]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_09]

//>> GET_[EPS_FIR_LOCAL_ACTION2_09]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_09]

//>> SET_[EPS_FIR_LOCAL_ACTION2_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_10]

//>> SET_[EPS_FIR_LOCAL_ACTION2_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_10]

//>> SET_[EPS_FIR_LOCAL_ACTION2_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_10]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_10]

//>> GET_[EPS_FIR_LOCAL_ACTION2_10]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_10]

//>> GET_[EPS_FIR_LOCAL_ACTION2_10]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_10]

//>> SET_[EPS_FIR_LOCAL_ACTION2_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_11]

//>> SET_[EPS_FIR_LOCAL_ACTION2_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_11]

//>> SET_[EPS_FIR_LOCAL_ACTION2_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_11]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_11]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_11]

//>> GET_[EPS_FIR_LOCAL_ACTION2_11]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_11]

//>> GET_[EPS_FIR_LOCAL_ACTION2_11]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_11]

//>> SET_[EPS_FIR_LOCAL_ACTION2_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_12]

//>> SET_[EPS_FIR_LOCAL_ACTION2_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_12]

//>> SET_[EPS_FIR_LOCAL_ACTION2_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_12]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_12]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_12]

//>> GET_[EPS_FIR_LOCAL_ACTION2_12]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_12]

//>> GET_[EPS_FIR_LOCAL_ACTION2_12]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_12]

//>> SET_[EPS_FIR_LOCAL_ACTION2_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_13]

//>> SET_[EPS_FIR_LOCAL_ACTION2_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_13]

//>> SET_[EPS_FIR_LOCAL_ACTION2_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_13]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_13]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_13]

//>> GET_[EPS_FIR_LOCAL_ACTION2_13]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_13]

//>> GET_[EPS_FIR_LOCAL_ACTION2_13]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_13]

//>> SET_[EPS_FIR_LOCAL_ACTION2_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_14]

//>> SET_[EPS_FIR_LOCAL_ACTION2_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_14]

//>> SET_[EPS_FIR_LOCAL_ACTION2_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_14]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_14]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_14]

//>> GET_[EPS_FIR_LOCAL_ACTION2_14]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_14]

//>> GET_[EPS_FIR_LOCAL_ACTION2_14]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_14]

//>> SET_[EPS_FIR_LOCAL_ACTION2_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_15]

//>> SET_[EPS_FIR_LOCAL_ACTION2_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_15]

//>> SET_[EPS_FIR_LOCAL_ACTION2_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_15]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_15]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_15]

//>> GET_[EPS_FIR_LOCAL_ACTION2_15]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_15]

//>> GET_[EPS_FIR_LOCAL_ACTION2_15]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_15]

//>> SET_[EPS_FIR_LOCAL_ACTION2_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_16]

//>> SET_[EPS_FIR_LOCAL_ACTION2_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_16]

//>> SET_[EPS_FIR_LOCAL_ACTION2_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_16]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_16]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_16]

//>> GET_[EPS_FIR_LOCAL_ACTION2_16]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_16]

//>> GET_[EPS_FIR_LOCAL_ACTION2_16]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_16]

//>> SET_[EPS_FIR_LOCAL_ACTION2_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_17]

//>> SET_[EPS_FIR_LOCAL_ACTION2_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_17]

//>> SET_[EPS_FIR_LOCAL_ACTION2_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_17]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_17]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_17]

//>> GET_[EPS_FIR_LOCAL_ACTION2_17]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_17]

//>> GET_[EPS_FIR_LOCAL_ACTION2_17]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_17]

//>> SET_[EPS_FIR_LOCAL_ACTION2_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_18]

//>> SET_[EPS_FIR_LOCAL_ACTION2_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_18]

//>> SET_[EPS_FIR_LOCAL_ACTION2_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_18]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_18]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_18]

//>> GET_[EPS_FIR_LOCAL_ACTION2_18]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_18]

//>> GET_[EPS_FIR_LOCAL_ACTION2_18]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_18]

//>> SET_[EPS_FIR_LOCAL_ACTION2_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_19]

//>> SET_[EPS_FIR_LOCAL_ACTION2_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_19]

//>> SET_[EPS_FIR_LOCAL_ACTION2_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_19]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_19]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_19]

//>> GET_[EPS_FIR_LOCAL_ACTION2_19]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_19]

//>> GET_[EPS_FIR_LOCAL_ACTION2_19]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_19]

//>> SET_[EPS_FIR_LOCAL_ACTION2_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_20]

//>> SET_[EPS_FIR_LOCAL_ACTION2_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_20]

//>> SET_[EPS_FIR_LOCAL_ACTION2_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_20]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_20]

//>> GET_[EPS_FIR_LOCAL_ACTION2_20]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_20]

//>> GET_[EPS_FIR_LOCAL_ACTION2_20]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_20]

//>> SET_[EPS_FIR_LOCAL_ACTION2_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_21]

//>> SET_[EPS_FIR_LOCAL_ACTION2_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_21]

//>> SET_[EPS_FIR_LOCAL_ACTION2_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_21]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_21]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_21]

//>> GET_[EPS_FIR_LOCAL_ACTION2_21]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_21]

//>> GET_[EPS_FIR_LOCAL_ACTION2_21]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_21]

//>> SET_[EPS_FIR_LOCAL_ACTION2_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_22]

//>> SET_[EPS_FIR_LOCAL_ACTION2_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_22]

//>> SET_[EPS_FIR_LOCAL_ACTION2_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_22]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_22]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_22]

//>> GET_[EPS_FIR_LOCAL_ACTION2_22]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_22]

//>> GET_[EPS_FIR_LOCAL_ACTION2_22]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_22]

//>> SET_[EPS_FIR_LOCAL_ACTION2_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_23]

//>> SET_[EPS_FIR_LOCAL_ACTION2_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_23]

//>> SET_[EPS_FIR_LOCAL_ACTION2_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_23]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_23]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_23]

//>> GET_[EPS_FIR_LOCAL_ACTION2_23]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_23]

//>> GET_[EPS_FIR_LOCAL_ACTION2_23]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_23]

//>> SET_[EPS_FIR_LOCAL_ACTION2_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_24]

//>> SET_[EPS_FIR_LOCAL_ACTION2_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_24]

//>> SET_[EPS_FIR_LOCAL_ACTION2_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_24]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_24]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_24]

//>> GET_[EPS_FIR_LOCAL_ACTION2_24]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_24]

//>> GET_[EPS_FIR_LOCAL_ACTION2_24]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_24]

//>> SET_[EPS_FIR_LOCAL_ACTION2_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_25]

//>> SET_[EPS_FIR_LOCAL_ACTION2_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_25]

//>> SET_[EPS_FIR_LOCAL_ACTION2_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_25]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_25]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_25]

//>> GET_[EPS_FIR_LOCAL_ACTION2_25]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_25]

//>> GET_[EPS_FIR_LOCAL_ACTION2_25]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_25]

//>> SET_[EPS_FIR_LOCAL_ACTION2_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_26]

//>> SET_[EPS_FIR_LOCAL_ACTION2_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_26]

//>> SET_[EPS_FIR_LOCAL_ACTION2_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_26]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_26]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_26]

//>> GET_[EPS_FIR_LOCAL_ACTION2_26]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_26]

//>> GET_[EPS_FIR_LOCAL_ACTION2_26]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_26]

//>> SET_[EPS_FIR_LOCAL_ACTION2_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_27]

//>> SET_[EPS_FIR_LOCAL_ACTION2_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_27]

//>> SET_[EPS_FIR_LOCAL_ACTION2_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_27]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_27]

//>> GET_[EPS_FIR_LOCAL_ACTION2_27]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_27]

//>> GET_[EPS_FIR_LOCAL_ACTION2_27]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_27]

//>> SET_[EPS_FIR_LOCAL_ACTION2_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_28]

//>> SET_[EPS_FIR_LOCAL_ACTION2_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_28]

//>> SET_[EPS_FIR_LOCAL_ACTION2_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_28]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_28]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_28]

//>> GET_[EPS_FIR_LOCAL_ACTION2_28]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_28]

//>> GET_[EPS_FIR_LOCAL_ACTION2_28]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_28]

//>> SET_[EPS_FIR_LOCAL_ACTION2_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_29]

//>> SET_[EPS_FIR_LOCAL_ACTION2_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_29]

//>> SET_[EPS_FIR_LOCAL_ACTION2_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_29]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_29]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_29]

//>> GET_[EPS_FIR_LOCAL_ACTION2_29]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_29]

//>> GET_[EPS_FIR_LOCAL_ACTION2_29]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_29]

//>> SET_[EPS_FIR_LOCAL_ACTION2_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_30]

//>> SET_[EPS_FIR_LOCAL_ACTION2_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_30]

//>> SET_[EPS_FIR_LOCAL_ACTION2_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_30]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_30]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_30]

//>> GET_[EPS_FIR_LOCAL_ACTION2_30]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_30]

//>> GET_[EPS_FIR_LOCAL_ACTION2_30]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_30]

//>> SET_[EPS_FIR_LOCAL_ACTION2_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_31]

//>> SET_[EPS_FIR_LOCAL_ACTION2_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_31]

//>> SET_[EPS_FIR_LOCAL_ACTION2_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_31]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_31]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_31]

//>> GET_[EPS_FIR_LOCAL_ACTION2_31]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_31]

//>> GET_[EPS_FIR_LOCAL_ACTION2_31]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_31]

//>> SET_[EPS_FIR_LOCAL_ACTION2_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_32]

//>> SET_[EPS_FIR_LOCAL_ACTION2_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_32]

//>> SET_[EPS_FIR_LOCAL_ACTION2_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_32]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_32]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_32]

//>> GET_[EPS_FIR_LOCAL_ACTION2_32]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_32]

//>> GET_[EPS_FIR_LOCAL_ACTION2_32]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_32]

//>> SET_[EPS_FIR_LOCAL_ACTION2_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_33]

//>> SET_[EPS_FIR_LOCAL_ACTION2_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_33]

//>> SET_[EPS_FIR_LOCAL_ACTION2_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_33]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_33]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_33]

//>> GET_[EPS_FIR_LOCAL_ACTION2_33]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_33]

//>> GET_[EPS_FIR_LOCAL_ACTION2_33]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_33]

//>> SET_[EPS_FIR_LOCAL_ACTION2_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_34]

//>> SET_[EPS_FIR_LOCAL_ACTION2_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_34]

//>> SET_[EPS_FIR_LOCAL_ACTION2_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_34]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_34]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_34]

//>> GET_[EPS_FIR_LOCAL_ACTION2_34]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_34]

//>> GET_[EPS_FIR_LOCAL_ACTION2_34]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_34]

//>> SET_[EPS_FIR_LOCAL_ACTION2_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_35]

//>> SET_[EPS_FIR_LOCAL_ACTION2_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_35]

//>> SET_[EPS_FIR_LOCAL_ACTION2_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_35]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_35]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_35]

//>> GET_[EPS_FIR_LOCAL_ACTION2_35]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_35]

//>> GET_[EPS_FIR_LOCAL_ACTION2_35]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_35]

//>> SET_[EPS_FIR_LOCAL_ACTION2_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_36]

//>> SET_[EPS_FIR_LOCAL_ACTION2_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_36]

//>> SET_[EPS_FIR_LOCAL_ACTION2_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_36]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_36]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_36]

//>> GET_[EPS_FIR_LOCAL_ACTION2_36]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_36]

//>> GET_[EPS_FIR_LOCAL_ACTION2_36]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_36]

//>> SET_[EPS_FIR_LOCAL_ACTION2_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_37]

//>> SET_[EPS_FIR_LOCAL_ACTION2_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_37]

//>> SET_[EPS_FIR_LOCAL_ACTION2_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_37]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_37]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_37]

//>> GET_[EPS_FIR_LOCAL_ACTION2_37]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_37]

//>> GET_[EPS_FIR_LOCAL_ACTION2_37]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_37]

//>> SET_[EPS_FIR_LOCAL_ACTION2_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_38]

//>> SET_[EPS_FIR_LOCAL_ACTION2_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_38]

//>> SET_[EPS_FIR_LOCAL_ACTION2_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_38]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_38]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_38]

//>> GET_[EPS_FIR_LOCAL_ACTION2_38]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_38]

//>> GET_[EPS_FIR_LOCAL_ACTION2_38]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_38]

//>> SET_[EPS_FIR_LOCAL_ACTION2_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_39]

//>> SET_[EPS_FIR_LOCAL_ACTION2_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_39]

//>> SET_[EPS_FIR_LOCAL_ACTION2_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_39]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_39]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_39]

//>> GET_[EPS_FIR_LOCAL_ACTION2_39]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_39]

//>> GET_[EPS_FIR_LOCAL_ACTION2_39]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_39]

//>> SET_[EPS_FIR_LOCAL_ACTION2_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_40]

//>> SET_[EPS_FIR_LOCAL_ACTION2_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_40]

//>> SET_[EPS_FIR_LOCAL_ACTION2_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_40]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_40]

//>> GET_[EPS_FIR_LOCAL_ACTION2_40]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_40]

//>> GET_[EPS_FIR_LOCAL_ACTION2_40]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_40]

//>> SET_[EPS_FIR_LOCAL_ACTION2_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_41]

//>> SET_[EPS_FIR_LOCAL_ACTION2_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_41]

//>> SET_[EPS_FIR_LOCAL_ACTION2_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_41]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_41]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_41]

//>> GET_[EPS_FIR_LOCAL_ACTION2_41]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_41]

//>> GET_[EPS_FIR_LOCAL_ACTION2_41]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_41]

//>> SET_[EPS_FIR_LOCAL_ACTION2_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_42]

//>> SET_[EPS_FIR_LOCAL_ACTION2_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_42]

//>> SET_[EPS_FIR_LOCAL_ACTION2_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_42]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_42]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_42]

//>> GET_[EPS_FIR_LOCAL_ACTION2_42]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_42]

//>> GET_[EPS_FIR_LOCAL_ACTION2_42]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_42]

//>> SET_[EPS_FIR_LOCAL_ACTION2_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_43]

//>> SET_[EPS_FIR_LOCAL_ACTION2_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_43]

//>> SET_[EPS_FIR_LOCAL_ACTION2_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_43]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_43]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_43]

//>> GET_[EPS_FIR_LOCAL_ACTION2_43]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_43]

//>> GET_[EPS_FIR_LOCAL_ACTION2_43]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_43]

//>> SET_[EPS_FIR_LOCAL_ACTION2_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_44]

//>> SET_[EPS_FIR_LOCAL_ACTION2_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_44]

//>> SET_[EPS_FIR_LOCAL_ACTION2_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_44]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_44]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_44]

//>> GET_[EPS_FIR_LOCAL_ACTION2_44]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_44]

//>> GET_[EPS_FIR_LOCAL_ACTION2_44]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_44]

//>> SET_[EPS_FIR_LOCAL_ACTION2_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_45]

//>> SET_[EPS_FIR_LOCAL_ACTION2_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_45]

//>> SET_[EPS_FIR_LOCAL_ACTION2_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_45]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_45]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_45]

//>> GET_[EPS_FIR_LOCAL_ACTION2_45]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_45]

//>> GET_[EPS_FIR_LOCAL_ACTION2_45]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_45]

//>> SET_[EPS_FIR_LOCAL_ACTION2_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_46]

//>> SET_[EPS_FIR_LOCAL_ACTION2_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_46]

//>> SET_[EPS_FIR_LOCAL_ACTION2_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_46]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_46]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_46]

//>> GET_[EPS_FIR_LOCAL_ACTION2_46]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_46]

//>> GET_[EPS_FIR_LOCAL_ACTION2_46]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_46]

//>> SET_[EPS_FIR_LOCAL_ACTION2_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_47]

//>> SET_[EPS_FIR_LOCAL_ACTION2_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_47]

//>> SET_[EPS_FIR_LOCAL_ACTION2_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_47]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_47]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_47]

//>> GET_[EPS_FIR_LOCAL_ACTION2_47]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_47]

//>> GET_[EPS_FIR_LOCAL_ACTION2_47]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_47]

//>> SET_[EPS_FIR_LOCAL_ACTION2_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_48]

//>> SET_[EPS_FIR_LOCAL_ACTION2_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_48]

//>> SET_[EPS_FIR_LOCAL_ACTION2_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_48]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_48]

//>> GET_[EPS_FIR_LOCAL_ACTION2_48]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_48]

//>> GET_[EPS_FIR_LOCAL_ACTION2_48]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_48]

//>> SET_[EPS_FIR_LOCAL_ACTION2_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_49]

//>> SET_[EPS_FIR_LOCAL_ACTION2_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_49]

//>> SET_[EPS_FIR_LOCAL_ACTION2_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_49]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_49]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_49]

//>> GET_[EPS_FIR_LOCAL_ACTION2_49]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_49]

//>> GET_[EPS_FIR_LOCAL_ACTION2_49]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_49]

//>> SET_[EPS_FIR_LOCAL_ACTION2_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_50]

//>> SET_[EPS_FIR_LOCAL_ACTION2_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_50]

//>> SET_[EPS_FIR_LOCAL_ACTION2_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_50]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_50]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_50]

//>> GET_[EPS_FIR_LOCAL_ACTION2_50]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_50]

//>> GET_[EPS_FIR_LOCAL_ACTION2_50]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_50]

//>> SET_[EPS_FIR_LOCAL_ACTION2_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_51]

//>> SET_[EPS_FIR_LOCAL_ACTION2_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_51]

//>> SET_[EPS_FIR_LOCAL_ACTION2_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_51]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_51]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_51]

//>> GET_[EPS_FIR_LOCAL_ACTION2_51]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_51]

//>> GET_[EPS_FIR_LOCAL_ACTION2_51]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_51]

//>> SET_[EPS_FIR_LOCAL_ACTION2_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_52]

//>> SET_[EPS_FIR_LOCAL_ACTION2_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_52]

//>> SET_[EPS_FIR_LOCAL_ACTION2_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_52]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_52]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_52]

//>> GET_[EPS_FIR_LOCAL_ACTION2_52]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_52]

//>> GET_[EPS_FIR_LOCAL_ACTION2_52]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_52]

//>> SET_[EPS_FIR_LOCAL_ACTION2_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_53]

//>> SET_[EPS_FIR_LOCAL_ACTION2_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_53]

//>> SET_[EPS_FIR_LOCAL_ACTION2_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_53]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_53]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_53]

//>> GET_[EPS_FIR_LOCAL_ACTION2_53]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_53]

//>> GET_[EPS_FIR_LOCAL_ACTION2_53]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_53]

//>> SET_[EPS_FIR_LOCAL_ACTION2_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_54]

//>> SET_[EPS_FIR_LOCAL_ACTION2_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_54]

//>> SET_[EPS_FIR_LOCAL_ACTION2_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_54]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_54]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_54]

//>> GET_[EPS_FIR_LOCAL_ACTION2_54]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_54]

//>> GET_[EPS_FIR_LOCAL_ACTION2_54]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_54]

//>> SET_[EPS_FIR_LOCAL_ACTION2_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_55]

//>> SET_[EPS_FIR_LOCAL_ACTION2_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_55]

//>> SET_[EPS_FIR_LOCAL_ACTION2_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_55]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_55]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_55]

//>> GET_[EPS_FIR_LOCAL_ACTION2_55]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_55]

//>> GET_[EPS_FIR_LOCAL_ACTION2_55]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_55]

//>> SET_[EPS_FIR_LOCAL_ACTION2_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_56]

//>> SET_[EPS_FIR_LOCAL_ACTION2_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_56]

//>> SET_[EPS_FIR_LOCAL_ACTION2_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_56]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_56]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_56]

//>> GET_[EPS_FIR_LOCAL_ACTION2_56]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_56]

//>> GET_[EPS_FIR_LOCAL_ACTION2_56]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_56]

//>> SET_[EPS_FIR_LOCAL_ACTION2_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_57]

//>> SET_[EPS_FIR_LOCAL_ACTION2_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_57]

//>> SET_[EPS_FIR_LOCAL_ACTION2_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_57]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_57]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_57]

//>> GET_[EPS_FIR_LOCAL_ACTION2_57]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_57]

//>> GET_[EPS_FIR_LOCAL_ACTION2_57]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_57]

//>> SET_[EPS_FIR_LOCAL_ACTION2_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_58]

//>> SET_[EPS_FIR_LOCAL_ACTION2_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_58]

//>> SET_[EPS_FIR_LOCAL_ACTION2_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_58]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_58]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_58]

//>> GET_[EPS_FIR_LOCAL_ACTION2_58]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_58]

//>> GET_[EPS_FIR_LOCAL_ACTION2_58]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_58]

//>> SET_[EPS_FIR_LOCAL_ACTION2_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_59]

//>> SET_[EPS_FIR_LOCAL_ACTION2_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_59]

//>> SET_[EPS_FIR_LOCAL_ACTION2_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_59]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_59]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_59]

//>> GET_[EPS_FIR_LOCAL_ACTION2_59]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_59]

//>> GET_[EPS_FIR_LOCAL_ACTION2_59]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_59]

//>> SET_[EPS_FIR_LOCAL_ACTION2_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_60]

//>> SET_[EPS_FIR_LOCAL_ACTION2_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_60]

//>> SET_[EPS_FIR_LOCAL_ACTION2_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_60]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_60]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_60]

//>> GET_[EPS_FIR_LOCAL_ACTION2_60]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_60]

//>> GET_[EPS_FIR_LOCAL_ACTION2_60]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_60]

//>> SET_[EPS_FIR_LOCAL_ACTION2_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_61]

//>> SET_[EPS_FIR_LOCAL_ACTION2_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_61]

//>> SET_[EPS_FIR_LOCAL_ACTION2_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_61]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_61]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_61]

//>> GET_[EPS_FIR_LOCAL_ACTION2_61]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_61]

//>> GET_[EPS_FIR_LOCAL_ACTION2_61]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_61]

//>> SET_[EPS_FIR_LOCAL_ACTION2_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_62]

//>> SET_[EPS_FIR_LOCAL_ACTION2_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_62]

//>> SET_[EPS_FIR_LOCAL_ACTION2_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_62]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_62]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_62]

//>> GET_[EPS_FIR_LOCAL_ACTION2_62]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_62]

//>> GET_[EPS_FIR_LOCAL_ACTION2_62]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_62]

//>> SET_[EPS_FIR_LOCAL_ACTION2_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_63]

//>> SET_[EPS_FIR_LOCAL_ACTION2_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION2_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_63]

//>> SET_[EPS_FIR_LOCAL_ACTION2_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION2_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION2_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION2_63]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION2_63]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION2_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION2_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION2_63]

//>> GET_[EPS_FIR_LOCAL_ACTION2_63]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION2_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION2_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_63]

//>> GET_[EPS_FIR_LOCAL_ACTION2_63]
static inline bool GET_EPS_FIR_LOCAL_ACTION2_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION2));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION2_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_FIR_LOCAL_ACTION2_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION2_63]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
