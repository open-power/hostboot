/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pec/reg00003.H $          */
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

#ifndef __PEC_REG00003_H_
#define __PEC_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> PREP_[CLOCK_STAT_NSL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLOCK_STAT_NSL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLOCK_STAT_NSL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLOCK_STAT_NSL]

//>> GET_[CLOCK_STAT_NSL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLOCK_STAT_NSL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLOCK_STAT_NSL;
#endif
    return fapi2::getScom(i_target, CLOCK_STAT_NSL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLOCK_STAT_NSL]

//>> PUT_[CLOCK_STAT_NSL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLOCK_STAT_NSL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return fapi2::putScom(i_target, CLOCK_STAT_NSL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLOCK_STAT_NSL]


//>> SET_[CLOCK_STAT_NSL_PERV_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_PERV_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_PERV_NSL]

//>> SET_[CLOCK_STAT_NSL_PERV_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_PERV_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_PERV_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_PERV_NSL]

//>> SET_[CLOCK_STAT_NSL_PERV_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_PERV_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_PERV_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_PERV_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_PERV_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_PERV_NSL]

//>> GET_[CLOCK_STAT_NSL_PERV_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_PERV_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_PERV_NSL]

//>> GET_[CLOCK_STAT_NSL_PERV_NSL]
static inline bool GET_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_PERV_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_PERV_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT1_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT1_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT1_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT1_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT1_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT1_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT1_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT1_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT1_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT1_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT1_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT1_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT1_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT1_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT1_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT1_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT1_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT1_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT1_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT2_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT2_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT2_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT2_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT2_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT2_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT2_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT2_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT2_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT2_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT2_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT2_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT2_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT2_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT2_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT2_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT2_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT2_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT2_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT3_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT3_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT3_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT3_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT3_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT3_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT3_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT3_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT3_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT3_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT3_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT3_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT3_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT3_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT3_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT3_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT3_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT3_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT3_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT4_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT4_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT4_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT4_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT4_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT4_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT4_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT4_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT4_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT4_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT4_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT4_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT4_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT4_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT4_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT4_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT4_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT4_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT4_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT5_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT5_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT5_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT5_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT5_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT5_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT5_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT5_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT5_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT5_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT5_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT5_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT5_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT5_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT5_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT5_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT5_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT5_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT5_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT6_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT6_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT6_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT6_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT6_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT6_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT6_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT6_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT6_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT6_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT6_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT6_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT6_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT6_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT6_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT6_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT6_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT6_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT6_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT7_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT7_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT7_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT7_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT7_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT7_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT7_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT7_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT7_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT7_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT7_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT7_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT7_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT7_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT7_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT7_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT7_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT7_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT7_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT8_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT8_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT8_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT8_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT8_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT8_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT8_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT8_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT8_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT8_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT8_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT8_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT8_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT8_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT8_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT8_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT8_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT8_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT8_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT9_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT9_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT9_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT9_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT9_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT9_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT9_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT9_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT9_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT9_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT9_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT9_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT9_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT9_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT9_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT9_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT9_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT9_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT9_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT10_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT10_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT10_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT10_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT10_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT10_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT10_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT10_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT10_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT10_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT10_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT10_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT10_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT10_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT10_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT10_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT10_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT10_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT10_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT11_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT11_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT11_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT11_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT11_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT11_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT11_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT11_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT11_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT11_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT11_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT11_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT11_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT11_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT11_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT11_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT11_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT11_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT11_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT12_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT12_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT12_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT12_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT12_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT12_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT12_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT12_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT12_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT12_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT12_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT12_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT12_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT12_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT12_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT12_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT12_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT12_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT12_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT13_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT13_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT13_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT13_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT13_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT13_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT13_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT13_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT13_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT13_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT13_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT13_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT13_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT13_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT13_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT13_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT13_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT13_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT13_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT14_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT14_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT14_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT14_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT14_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_NSL_UNIT14_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT14_NSL]

//>> SET_[CLOCK_STAT_NSL_UNIT14_NSL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.setBit<CLOCK_STAT_NSL_UNIT14_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_NSL_UNIT14_NSL]

//>> CLEAR_[CLOCK_STAT_NSL_UNIT14_NSL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<CLOCK_STAT_NSL_UNIT14_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_NSL_UNIT14_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT14_NSL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<CLOCK_STAT_NSL_UNIT14_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT14_NSL]

//>> GET_[CLOCK_STAT_NSL_UNIT14_NSL]
static inline bool GET_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_NSL));
#endif
    return i_data.getBit<CLOCK_STAT_NSL_UNIT14_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_NSL_UNIT14_NSL]

//>> PREP_[EPS_THERM_WSUB_DTS_RESULT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_DTS_RESULT2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_DTS_RESULT2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB_DTS_RESULT2]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_DTS_RESULT2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_DTS_RESULT2;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_DTS_RESULT2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT2]

//>> PUT_[EPS_THERM_WSUB_DTS_RESULT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_DTS_RESULT2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT2));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_DTS_RESULT2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB_DTS_RESULT2]


//>> SET_[EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT2));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT,
           EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT2));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT,
           EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT2));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT,
           EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT]

//>> PREP_[EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB_MODE_REG]

//>> GET_[EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_MODE_REG;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG]

//>> PUT_[EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB_MODE_REG]


//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline bool GET_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline bool GET_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline bool GET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> CLEAR_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> GET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> GET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline bool GET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> CLEAR_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> GET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> GET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline bool GET_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline bool GET_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline bool GET_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> PREP_[LOCAL_XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_XSTOP]

//>> GET_[LOCAL_XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP;
#endif
    return fapi2::getScom(i_target, LOCAL_XSTOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_XSTOP]

//>> PUT_[LOCAL_XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return fapi2::putScom(i_target, LOCAL_XSTOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_XSTOP]


//>> SET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]

//>> SET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_ANY_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]

//>> SET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]

//>> CLEAR_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]

//>> GET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]

//>> GET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]
static inline bool GET_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_ANY_LOCAL_XSTOP]

//>> SET_[LOCAL_XSTOP_RESERVED1L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_RESERVED1L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED1L]

//>> SET_[LOCAL_XSTOP_RESERVED1L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED1L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_RESERVED1L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED1L]

//>> SET_[LOCAL_XSTOP_RESERVED1L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED1L]

//>> CLEAR_[LOCAL_XSTOP_RESERVED1L]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_RESERVED1L]

//>> GET_[LOCAL_XSTOP_RESERVED1L]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_RESERVED1L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_RESERVED1L]

//>> GET_[LOCAL_XSTOP_RESERVED1L]
static inline bool GET_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_RESERVED1L]

//>> SET_[LOCAL_XSTOP_RESERVED2L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_RESERVED2L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED2L]

//>> SET_[LOCAL_XSTOP_RESERVED2L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED2L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_RESERVED2L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED2L]

//>> SET_[LOCAL_XSTOP_RESERVED2L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED2L]

//>> CLEAR_[LOCAL_XSTOP_RESERVED2L]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_RESERVED2L]

//>> GET_[LOCAL_XSTOP_RESERVED2L]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_RESERVED2L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_RESERVED2L]

//>> GET_[LOCAL_XSTOP_RESERVED2L]
static inline bool GET_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_RESERVED2L]

//>> SET_[LOCAL_XSTOP_RESERVED3L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_RESERVED3L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED3L]

//>> SET_[LOCAL_XSTOP_RESERVED3L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED3L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_RESERVED3L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED3L]

//>> SET_[LOCAL_XSTOP_RESERVED3L]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_RESERVED3L]

//>> CLEAR_[LOCAL_XSTOP_RESERVED3L]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_RESERVED3L]

//>> GET_[LOCAL_XSTOP_RESERVED3L]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_RESERVED3L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_RESERVED3L]

//>> GET_[LOCAL_XSTOP_RESERVED3L]
static inline bool GET_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_RESERVED3L]

//>> SET_[LOCAL_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_PERV]

//>> SET_[LOCAL_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_PERV]

//>> SET_[LOCAL_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_PERV]

//>> CLEAR_[LOCAL_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_PERV]

//>> GET_[LOCAL_XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_PERV]

//>> GET_[LOCAL_XSTOP_PERV]
static inline bool GET_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_PERV]

//>> SET_[LOCAL_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN05]

//>> SET_[LOCAL_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN05]

//>> SET_[LOCAL_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN05]

//>> CLEAR_[LOCAL_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN05]

//>> GET_[LOCAL_XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN05]

//>> GET_[LOCAL_XSTOP_IN05]
static inline bool GET_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN05]

//>> SET_[LOCAL_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN06]

//>> SET_[LOCAL_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN06]

//>> SET_[LOCAL_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN06]

//>> CLEAR_[LOCAL_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN06]

//>> GET_[LOCAL_XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN06]

//>> GET_[LOCAL_XSTOP_IN06]
static inline bool GET_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN06]

//>> SET_[LOCAL_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN07]

//>> SET_[LOCAL_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN07]

//>> SET_[LOCAL_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN07]

//>> CLEAR_[LOCAL_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN07]

//>> GET_[LOCAL_XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN07]

//>> GET_[LOCAL_XSTOP_IN07]
static inline bool GET_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN07]

//>> SET_[LOCAL_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN08]

//>> SET_[LOCAL_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN08]

//>> SET_[LOCAL_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN08]

//>> CLEAR_[LOCAL_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN08]

//>> GET_[LOCAL_XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN08]

//>> GET_[LOCAL_XSTOP_IN08]
static inline bool GET_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN08]

//>> SET_[LOCAL_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN09]

//>> SET_[LOCAL_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN09]

//>> SET_[LOCAL_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN09]

//>> CLEAR_[LOCAL_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN09]

//>> GET_[LOCAL_XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN09]

//>> GET_[LOCAL_XSTOP_IN09]
static inline bool GET_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN09]

//>> SET_[LOCAL_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN10]

//>> SET_[LOCAL_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN10]

//>> SET_[LOCAL_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN10]

//>> CLEAR_[LOCAL_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN10]

//>> GET_[LOCAL_XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN10]

//>> GET_[LOCAL_XSTOP_IN10]
static inline bool GET_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN10]

//>> SET_[LOCAL_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN11]

//>> SET_[LOCAL_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN11]

//>> SET_[LOCAL_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN11]

//>> CLEAR_[LOCAL_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN11]

//>> GET_[LOCAL_XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN11]

//>> GET_[LOCAL_XSTOP_IN11]
static inline bool GET_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN11]

//>> SET_[LOCAL_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN12]

//>> SET_[LOCAL_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN12]

//>> SET_[LOCAL_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN12]

//>> CLEAR_[LOCAL_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN12]

//>> GET_[LOCAL_XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN12]

//>> GET_[LOCAL_XSTOP_IN12]
static inline bool GET_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN12]

//>> SET_[LOCAL_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN13]

//>> SET_[LOCAL_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN13]

//>> SET_[LOCAL_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN13]

//>> CLEAR_[LOCAL_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN13]

//>> GET_[LOCAL_XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN13]

//>> GET_[LOCAL_XSTOP_IN13]
static inline bool GET_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN13]

//>> SET_[LOCAL_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN14]

//>> SET_[LOCAL_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN14]

//>> SET_[LOCAL_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN14]

//>> CLEAR_[LOCAL_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN14]

//>> GET_[LOCAL_XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN14]

//>> GET_[LOCAL_XSTOP_IN14]
static inline bool GET_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN14]

//>> SET_[LOCAL_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN15]

//>> SET_[LOCAL_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN15]

//>> SET_[LOCAL_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.setBit<LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_IN15]

//>> CLEAR_[LOCAL_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return o_data.clearBit<LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_IN15]

//>> GET_[LOCAL_XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN15]

//>> GET_[LOCAL_XSTOP_IN15]
static inline bool GET_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP));
#endif
    return i_data.getBit<LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_IN15]

//>> PREP_[MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MULTICAST_GROUP_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MULTICAST_GROUP_1]

//>> GET_[MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MULTICAST_GROUP_1;
#endif
    return fapi2::getScom(i_target, MULTICAST_GROUP_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MULTICAST_GROUP_1]

//>> PUT_[MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_1));
#endif
    return fapi2::putScom(i_target, MULTICAST_GROUP_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MULTICAST_GROUP_1]


//>> SET_[MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& SET_MULTICAST_GROUP_1_MULTICAST1_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_1));
#endif
    return o_data.insertFromRight<MULTICAST_GROUP_1_MULTICAST1_GROUP,
           MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> SET_[MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& SET_MULTICAST_GROUP_1_MULTICAST1_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_1));
#endif
    return o_data.insertFromRight<MULTICAST_GROUP_1_MULTICAST1_GROUP,
           MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> GET_[MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& GET_MULTICAST_GROUP_1_MULTICAST1_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_1));
#endif
    return i_data.extractToRight<MULTICAST_GROUP_1_MULTICAST1_GROUP,
           MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> PREP_[NET_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL0_RW]

//>> GET_[NET_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL0_RW;
#endif
    return fapi2::getScom(i_target, NET_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL0_RW]

//>> PUT_[NET_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL0_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL0_RW]

//>> PREP_[NET_CTRL0_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL0_RW_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL0_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL0_RW_WAND]

//>> GET_[NET_CTRL0_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL0_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL0_RW_WAND;
#endif
    return fapi2::getScom(i_target, NET_CTRL0_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL0_RW_WAND]

//>> PUT_[NET_CTRL0_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL0_RW_WAND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL0_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL0_RW_WAND]

//>> PREP_[NET_CTRL0_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL0_RW_WOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL0_RW_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL0_RW_WOR]

//>> GET_[NET_CTRL0_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL0_RW_WOR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL0_RW_WOR;
#endif
    return fapi2::getScom(i_target, NET_CTRL0_RW_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL0_RW_WOR]

//>> PUT_[NET_CTRL0_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL0_RW_WOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL0_RW_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL0_RW_WOR]


//>> SET_[NET_CTRL0_CHIPLET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CHIPLET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CHIPLET_ENABLE]

//>> SET_[NET_CTRL0_CHIPLET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CHIPLET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CHIPLET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CHIPLET_ENABLE]

//>> SET_[NET_CTRL0_CHIPLET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_CHIPLET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CHIPLET_ENABLE]

//>> CLEAR_[NET_CTRL0_CHIPLET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_CHIPLET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_CHIPLET_ENABLE]

//>> GET_[NET_CTRL0_CHIPLET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_CHIPLET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CHIPLET_ENABLE]

//>> GET_[NET_CTRL0_CHIPLET_ENABLE]
static inline bool GET_NET_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_CHIPLET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CHIPLET_ENABLE]

//>> SET_[NET_CTRL0_PCB_EP_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PCB_EP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PCB_EP_RESET]

//>> SET_[NET_CTRL0_PCB_EP_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PCB_EP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PCB_EP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PCB_EP_RESET]

//>> SET_[NET_CTRL0_PCB_EP_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_PCB_EP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PCB_EP_RESET]

//>> CLEAR_[NET_CTRL0_PCB_EP_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_PCB_EP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_PCB_EP_RESET]

//>> GET_[NET_CTRL0_PCB_EP_RESET]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_PCB_EP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PCB_EP_RESET]

//>> GET_[NET_CTRL0_PCB_EP_RESET]
static inline bool GET_NET_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_PCB_EP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PCB_EP_RESET]

//>> SET_[NET_CTRL0_CLK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CLK_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CLK_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CLK_ASYNC_RESET]

//>> SET_[NET_CTRL0_CLK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CLK_ASYNC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CLK_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CLK_ASYNC_RESET]

//>> SET_[NET_CTRL0_CLK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CLK_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_CLK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CLK_ASYNC_RESET]

//>> CLEAR_[NET_CTRL0_CLK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_CLK_ASYNC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_CLK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_CLK_ASYNC_RESET]

//>> GET_[NET_CTRL0_CLK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_CLK_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_CLK_ASYNC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CLK_ASYNC_RESET]

//>> GET_[NET_CTRL0_CLK_ASYNC_RESET]
static inline bool GET_NET_CTRL0_CLK_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_CLK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CLK_ASYNC_RESET]

//>> SET_[NET_CTRL0_PLL_TEST_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PLL_TEST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_TEST_EN]

//>> SET_[NET_CTRL0_PLL_TEST_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_TEST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PLL_TEST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_TEST_EN]

//>> SET_[NET_CTRL0_PLL_TEST_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_PLL_TEST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_TEST_EN]

//>> CLEAR_[NET_CTRL0_PLL_TEST_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_PLL_TEST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_PLL_TEST_EN]

//>> GET_[NET_CTRL0_PLL_TEST_EN]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_PLL_TEST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PLL_TEST_EN]

//>> GET_[NET_CTRL0_PLL_TEST_EN]
static inline bool GET_NET_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_PLL_TEST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PLL_TEST_EN]

//>> SET_[NET_CTRL0_PLL_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PLL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_RESET]

//>> SET_[NET_CTRL0_PLL_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PLL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_RESET]

//>> SET_[NET_CTRL0_PLL_RESET]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_PLL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_RESET]

//>> CLEAR_[NET_CTRL0_PLL_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_PLL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_PLL_RESET]

//>> GET_[NET_CTRL0_PLL_RESET]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_PLL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PLL_RESET]

//>> GET_[NET_CTRL0_PLL_RESET]
static inline bool GET_NET_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_PLL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PLL_RESET]

//>> SET_[NET_CTRL0_PLL_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PLL_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_BYPASS]

//>> SET_[NET_CTRL0_PLL_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PLL_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_BYPASS]

//>> SET_[NET_CTRL0_PLL_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_PLL_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLL_BYPASS]

//>> CLEAR_[NET_CTRL0_PLL_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_PLL_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_PLL_BYPASS]

//>> GET_[NET_CTRL0_PLL_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_PLL_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PLL_BYPASS]

//>> GET_[NET_CTRL0_PLL_BYPASS]
static inline bool GET_NET_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_PLL_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PLL_BYPASS]

//>> SET_[NET_CTRL0_VITAL_SCAN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_SCAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_SCAN]

//>> SET_[NET_CTRL0_VITAL_SCAN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_SCAN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_SCAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_SCAN]

//>> SET_[NET_CTRL0_VITAL_SCAN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_VITAL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_SCAN]

//>> CLEAR_[NET_CTRL0_VITAL_SCAN]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_VITAL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_VITAL_SCAN]

//>> GET_[NET_CTRL0_VITAL_SCAN]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_VITAL_SCAN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_SCAN]

//>> GET_[NET_CTRL0_VITAL_SCAN]
static inline bool GET_NET_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_VITAL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_SCAN]

//>> SET_[NET_CTRL0_VITAL_SCAN_IN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_SCAN_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_SCAN_IN]

//>> SET_[NET_CTRL0_VITAL_SCAN_IN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_SCAN_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_SCAN_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_SCAN_IN]

//>> SET_[NET_CTRL0_VITAL_SCAN_IN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_VITAL_SCAN_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_SCAN_IN]

//>> CLEAR_[NET_CTRL0_VITAL_SCAN_IN]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_VITAL_SCAN_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_VITAL_SCAN_IN]

//>> GET_[NET_CTRL0_VITAL_SCAN_IN]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_VITAL_SCAN_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_SCAN_IN]

//>> GET_[NET_CTRL0_VITAL_SCAN_IN]
static inline bool GET_NET_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_VITAL_SCAN_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_SCAN_IN]

//>> SET_[NET_CTRL0_VITAL_PHASE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_PHASE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_PHASE]

//>> SET_[NET_CTRL0_VITAL_PHASE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_PHASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_PHASE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_PHASE]

//>> SET_[NET_CTRL0_VITAL_PHASE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_VITAL_PHASE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_PHASE]

//>> CLEAR_[NET_CTRL0_VITAL_PHASE]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_VITAL_PHASE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_VITAL_PHASE]

//>> GET_[NET_CTRL0_VITAL_PHASE]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_VITAL_PHASE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_PHASE]

//>> GET_[NET_CTRL0_VITAL_PHASE]
static inline bool GET_NET_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_VITAL_PHASE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_PHASE]

//>> SET_[NET_CTRL0_FLUSH_ALIGN_OVR]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FLUSH_ALIGN_OVR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_FLUSH_ALIGN_OVR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FLUSH_ALIGN_OVR]

//>> SET_[NET_CTRL0_FLUSH_ALIGN_OVR]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FLUSH_ALIGN_OVR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_FLUSH_ALIGN_OVR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FLUSH_ALIGN_OVR]

//>> SET_[NET_CTRL0_FLUSH_ALIGN_OVR]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FLUSH_ALIGN_OVR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_FLUSH_ALIGN_OVR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FLUSH_ALIGN_OVR]

//>> CLEAR_[NET_CTRL0_FLUSH_ALIGN_OVR]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_FLUSH_ALIGN_OVR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_FLUSH_ALIGN_OVR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_FLUSH_ALIGN_OVR]

//>> GET_[NET_CTRL0_FLUSH_ALIGN_OVR]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_FLUSH_ALIGN_OVR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_FLUSH_ALIGN_OVR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_FLUSH_ALIGN_OVR]

//>> GET_[NET_CTRL0_FLUSH_ALIGN_OVR]
static inline bool GET_NET_CTRL0_FLUSH_ALIGN_OVR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_FLUSH_ALIGN_OVR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_FLUSH_ALIGN_OVR]

//>> SET_[NET_CTRL0_VITAL_AL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_AL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_AL]

//>> SET_[NET_CTRL0_VITAL_AL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_AL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_AL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_AL]

//>> SET_[NET_CTRL0_VITAL_AL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_VITAL_AL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_AL]

//>> CLEAR_[NET_CTRL0_VITAL_AL]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_VITAL_AL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_VITAL_AL]

//>> GET_[NET_CTRL0_VITAL_AL]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_VITAL_AL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_AL]

//>> GET_[NET_CTRL0_VITAL_AL]
static inline bool GET_NET_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_VITAL_AL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_AL]

//>> SET_[NET_CTRL0_ACT_DIS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_ACT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ACT_DIS]

//>> SET_[NET_CTRL0_ACT_DIS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ACT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_ACT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ACT_DIS]

//>> SET_[NET_CTRL0_ACT_DIS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_ACT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ACT_DIS]

//>> CLEAR_[NET_CTRL0_ACT_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_ACT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_ACT_DIS]

//>> GET_[NET_CTRL0_ACT_DIS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_ACT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_ACT_DIS]

//>> GET_[NET_CTRL0_ACT_DIS]
static inline bool GET_NET_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_ACT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_ACT_DIS]

//>> SET_[NET_CTRL0_TOADMODE_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_TOADMODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_TOADMODE_EN]

//>> SET_[NET_CTRL0_TOADMODE_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_TOADMODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_TOADMODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_TOADMODE_EN]

//>> SET_[NET_CTRL0_TOADMODE_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_TOADMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_TOADMODE_EN]

//>> CLEAR_[NET_CTRL0_TOADMODE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_TOADMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_TOADMODE_EN]

//>> GET_[NET_CTRL0_TOADMODE_EN]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_TOADMODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_TOADMODE_EN]

//>> GET_[NET_CTRL0_TOADMODE_EN]
static inline bool GET_NET_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_TOADMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_TOADMODE_EN]

//>> SET_[NET_CTRL0_SYNC_PULSE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_SYNC_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_SYNC_PULSE]

//>> SET_[NET_CTRL0_SYNC_PULSE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_SYNC_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_SYNC_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_SYNC_PULSE]

//>> SET_[NET_CTRL0_SYNC_PULSE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_SYNC_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_SYNC_PULSE]

//>> CLEAR_[NET_CTRL0_SYNC_PULSE]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_SYNC_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_SYNC_PULSE]

//>> GET_[NET_CTRL0_SYNC_PULSE]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_SYNC_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_SYNC_PULSE]

//>> GET_[NET_CTRL0_SYNC_PULSE]
static inline bool GET_NET_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_SYNC_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_SYNC_PULSE]

//>> SET_[NET_CTRL0_MPW3]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_MPW3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_MPW3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_MPW3]

//>> SET_[NET_CTRL0_MPW3]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_MPW3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_MPW3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_MPW3]

//>> SET_[NET_CTRL0_MPW3]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_MPW3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_MPW3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_MPW3]

//>> CLEAR_[NET_CTRL0_MPW3]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_MPW3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_MPW3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_MPW3]

//>> GET_[NET_CTRL0_MPW3]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_MPW3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_MPW3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_MPW3]

//>> GET_[NET_CTRL0_MPW3]
static inline bool GET_NET_CTRL0_MPW3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_MPW3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_MPW3]

//>> SET_[NET_CTRL0_DELAY_LCLKR]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_DELAY_LCLKR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_DELAY_LCLKR]

//>> SET_[NET_CTRL0_DELAY_LCLKR]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_DELAY_LCLKR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_DELAY_LCLKR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_DELAY_LCLKR]

//>> SET_[NET_CTRL0_DELAY_LCLKR]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_DELAY_LCLKR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_DELAY_LCLKR]

//>> CLEAR_[NET_CTRL0_DELAY_LCLKR]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_DELAY_LCLKR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_DELAY_LCLKR]

//>> GET_[NET_CTRL0_DELAY_LCLKR]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_DELAY_LCLKR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_DELAY_LCLKR]

//>> GET_[NET_CTRL0_DELAY_LCLKR]
static inline bool GET_NET_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_DELAY_LCLKR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_DELAY_LCLKR]

//>> SET_[NET_CTRL0_VITAL_THOLD]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_THOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_THOLD]

//>> SET_[NET_CTRL0_VITAL_THOLD]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_THOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_VITAL_THOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_THOLD]

//>> SET_[NET_CTRL0_VITAL_THOLD]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_VITAL_THOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_VITAL_THOLD]

//>> CLEAR_[NET_CTRL0_VITAL_THOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_VITAL_THOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_VITAL_THOLD]

//>> GET_[NET_CTRL0_VITAL_THOLD]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_VITAL_THOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_THOLD]

//>> GET_[NET_CTRL0_VITAL_THOLD]
static inline bool GET_NET_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_VITAL_THOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_VITAL_THOLD]

//>> SET_[NET_CTRL0_FLUSH_SCAN_N]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_FLUSH_SCAN_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FLUSH_SCAN_N]

//>> SET_[NET_CTRL0_FLUSH_SCAN_N]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FLUSH_SCAN_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_FLUSH_SCAN_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FLUSH_SCAN_N]

//>> SET_[NET_CTRL0_FLUSH_SCAN_N]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_FLUSH_SCAN_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FLUSH_SCAN_N]

//>> CLEAR_[NET_CTRL0_FLUSH_SCAN_N]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_FLUSH_SCAN_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_FLUSH_SCAN_N]

//>> GET_[NET_CTRL0_FLUSH_SCAN_N]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_FLUSH_SCAN_N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_FLUSH_SCAN_N]

//>> GET_[NET_CTRL0_FLUSH_SCAN_N]
static inline bool GET_NET_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_FLUSH_SCAN_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_FLUSH_SCAN_N]

//>> SET_[NET_CTRL0_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FENCE_EN]

//>> SET_[NET_CTRL0_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FENCE_EN]

//>> SET_[NET_CTRL0_FENCE_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FENCE_EN]

//>> CLEAR_[NET_CTRL0_FENCE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_FENCE_EN]

//>> GET_[NET_CTRL0_FENCE_EN]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_FENCE_EN]

//>> GET_[NET_CTRL0_FENCE_EN]
static inline bool GET_NET_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_FENCE_EN]

//>> SET_[NET_CTRL0_CPLT_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CPLT_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_RCTRL]

//>> SET_[NET_CTRL0_CPLT_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_RCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CPLT_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_RCTRL]

//>> SET_[NET_CTRL0_CPLT_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_CPLT_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_RCTRL]

//>> CLEAR_[NET_CTRL0_CPLT_RCTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_CPLT_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_CPLT_RCTRL]

//>> GET_[NET_CTRL0_CPLT_RCTRL]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_CPLT_RCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CPLT_RCTRL]

//>> GET_[NET_CTRL0_CPLT_RCTRL]
static inline bool GET_NET_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_CPLT_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CPLT_RCTRL]

//>> SET_[NET_CTRL0_CPLT_DCTRL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CPLT_DCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_DCTRL]

//>> SET_[NET_CTRL0_CPLT_DCTRL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_DCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CPLT_DCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_DCTRL]

//>> SET_[NET_CTRL0_CPLT_DCTRL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_CPLT_DCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_DCTRL]

//>> CLEAR_[NET_CTRL0_CPLT_DCTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_CPLT_DCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_CPLT_DCTRL]

//>> GET_[NET_CTRL0_CPLT_DCTRL]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_CPLT_DCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CPLT_DCTRL]

//>> GET_[NET_CTRL0_CPLT_DCTRL]
static inline bool GET_NET_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_CPLT_DCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CPLT_DCTRL]

//>> SET_[NET_CTRL0_CPLT_RCTRL2]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CPLT_RCTRL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_RCTRL2]

//>> SET_[NET_CTRL0_CPLT_RCTRL2]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_RCTRL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_CPLT_RCTRL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_RCTRL2]

//>> SET_[NET_CTRL0_CPLT_RCTRL2]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_CPLT_RCTRL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_CPLT_RCTRL2]

//>> CLEAR_[NET_CTRL0_CPLT_RCTRL2]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_CPLT_RCTRL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_CPLT_RCTRL2]

//>> GET_[NET_CTRL0_CPLT_RCTRL2]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_CPLT_RCTRL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CPLT_RCTRL2]

//>> GET_[NET_CTRL0_CPLT_RCTRL2]
static inline bool GET_NET_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_CPLT_RCTRL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_CPLT_RCTRL2]

//>> SET_[NET_CTRL0_ADJ_FUNC_CLKSEL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ADJ_FUNC_CLKSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_ADJ_FUNC_CLKSEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ADJ_FUNC_CLKSEL]

//>> SET_[NET_CTRL0_ADJ_FUNC_CLKSEL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ADJ_FUNC_CLKSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_ADJ_FUNC_CLKSEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ADJ_FUNC_CLKSEL]

//>> SET_[NET_CTRL0_ADJ_FUNC_CLKSEL]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ADJ_FUNC_CLKSEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_ADJ_FUNC_CLKSEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ADJ_FUNC_CLKSEL]

//>> CLEAR_[NET_CTRL0_ADJ_FUNC_CLKSEL]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_ADJ_FUNC_CLKSEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_ADJ_FUNC_CLKSEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_ADJ_FUNC_CLKSEL]

//>> GET_[NET_CTRL0_ADJ_FUNC_CLKSEL]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_ADJ_FUNC_CLKSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_ADJ_FUNC_CLKSEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_ADJ_FUNC_CLKSEL]

//>> GET_[NET_CTRL0_ADJ_FUNC_CLKSEL]
static inline bool GET_NET_CTRL0_ADJ_FUNC_CLKSEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_ADJ_FUNC_CLKSEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_ADJ_FUNC_CLKSEL]

//>> SET_[NET_CTRL0_PM_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PM_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PM_ACCESS]

//>> SET_[NET_CTRL0_PM_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PM_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PM_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PM_ACCESS]

//>> SET_[NET_CTRL0_PM_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_PM_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PM_ACCESS]

//>> CLEAR_[NET_CTRL0_PM_ACCESS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_PM_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_PM_ACCESS]

//>> GET_[NET_CTRL0_PM_ACCESS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_PM_ACCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PM_ACCESS]

//>> GET_[NET_CTRL0_PM_ACCESS]
static inline bool GET_NET_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_PM_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PM_ACCESS]

//>> SET_[NET_CTRL0_FUNC_LCB_EDIS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_FUNC_LCB_EDIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FUNC_LCB_EDIS]

//>> SET_[NET_CTRL0_FUNC_LCB_EDIS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FUNC_LCB_EDIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_FUNC_LCB_EDIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FUNC_LCB_EDIS]

//>> SET_[NET_CTRL0_FUNC_LCB_EDIS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_FUNC_LCB_EDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_FUNC_LCB_EDIS]

//>> CLEAR_[NET_CTRL0_FUNC_LCB_EDIS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_FUNC_LCB_EDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_FUNC_LCB_EDIS]

//>> GET_[NET_CTRL0_FUNC_LCB_EDIS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_FUNC_LCB_EDIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_FUNC_LCB_EDIS]

//>> GET_[NET_CTRL0_FUNC_LCB_EDIS]
static inline bool GET_NET_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_FUNC_LCB_EDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_FUNC_LCB_EDIS]

//>> SET_[NET_CTRL0_TP_FENCE_PCB]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_TP_FENCE_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_TP_FENCE_PCB]

//>> SET_[NET_CTRL0_TP_FENCE_PCB]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_TP_FENCE_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_TP_FENCE_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_TP_FENCE_PCB]

//>> SET_[NET_CTRL0_TP_FENCE_PCB]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_TP_FENCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_TP_FENCE_PCB]

//>> CLEAR_[NET_CTRL0_TP_FENCE_PCB]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_TP_FENCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_TP_FENCE_PCB]

//>> GET_[NET_CTRL0_TP_FENCE_PCB]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_TP_FENCE_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_TP_FENCE_PCB]

//>> GET_[NET_CTRL0_TP_FENCE_PCB]
static inline bool GET_NET_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_TP_FENCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_TP_FENCE_PCB]

//>> SET_[NET_CTRL0_LVLTRANS_FENCE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_LVLTRANS_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_LVLTRANS_FENCE]

//>> SET_[NET_CTRL0_LVLTRANS_FENCE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_LVLTRANS_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_LVLTRANS_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_LVLTRANS_FENCE]

//>> SET_[NET_CTRL0_LVLTRANS_FENCE]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_LVLTRANS_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_LVLTRANS_FENCE]

//>> CLEAR_[NET_CTRL0_LVLTRANS_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_LVLTRANS_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_LVLTRANS_FENCE]

//>> GET_[NET_CTRL0_LVLTRANS_FENCE]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_LVLTRANS_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_LVLTRANS_FENCE]

//>> GET_[NET_CTRL0_LVLTRANS_FENCE]
static inline bool GET_NET_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_LVLTRANS_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_LVLTRANS_FENCE]

//>> SET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ARRAY_WRITE_ASSIST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_ARRAY_WRITE_ASSIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]

//>> SET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ARRAY_WRITE_ASSIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_ARRAY_WRITE_ASSIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]

//>> SET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_ARRAY_WRITE_ASSIST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_ARRAY_WRITE_ASSIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]

//>> CLEAR_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_ARRAY_WRITE_ASSIST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_ARRAY_WRITE_ASSIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]

//>> GET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_ARRAY_WRITE_ASSIST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_ARRAY_WRITE_ASSIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]

//>> GET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]
static inline bool GET_NET_CTRL0_ARRAY_WRITE_ASSIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_ARRAY_WRITE_ASSIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_ARRAY_WRITE_ASSIST_EN]

//>> SET_[NET_CTRL0_HTB_INTEST]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_HTB_INTEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_HTB_INTEST]

//>> SET_[NET_CTRL0_HTB_INTEST]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_HTB_INTEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_HTB_INTEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_HTB_INTEST]

//>> SET_[NET_CTRL0_HTB_INTEST]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_HTB_INTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_HTB_INTEST]

//>> CLEAR_[NET_CTRL0_HTB_INTEST]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_HTB_INTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_HTB_INTEST]

//>> GET_[NET_CTRL0_HTB_INTEST]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_HTB_INTEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_HTB_INTEST]

//>> GET_[NET_CTRL0_HTB_INTEST]
static inline bool GET_NET_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_HTB_INTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_HTB_INTEST]

//>> SET_[NET_CTRL0_HTB_EXTEST]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_HTB_EXTEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_HTB_EXTEST]

//>> SET_[NET_CTRL0_HTB_EXTEST]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_HTB_EXTEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_HTB_EXTEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_HTB_EXTEST]

//>> SET_[NET_CTRL0_HTB_EXTEST]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_HTB_EXTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_HTB_EXTEST]

//>> CLEAR_[NET_CTRL0_HTB_EXTEST]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_HTB_EXTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_HTB_EXTEST]

//>> GET_[NET_CTRL0_HTB_EXTEST]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_HTB_EXTEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_HTB_EXTEST]

//>> GET_[NET_CTRL0_HTB_EXTEST]
static inline bool GET_NET_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_HTB_EXTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_HTB_EXTEST]

//>> SET_[NET_CTRL0_OOB_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_OOB_PROTECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_OOB_PROTECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_OOB_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_OOB_PROTECTION]

//>> SET_[NET_CTRL0_OOB_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_OOB_PROTECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_OOB_PROTECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_OOB_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_OOB_PROTECTION]

//>> SET_[NET_CTRL0_OOB_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_OOB_PROTECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_OOB_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_OOB_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_OOB_PROTECTION]

//>> CLEAR_[NET_CTRL0_OOB_PROTECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_OOB_PROTECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_OOB_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_OOB_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_OOB_PROTECTION]

//>> GET_[NET_CTRL0_OOB_PROTECTION]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_OOB_PROTECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_OOB_PROTECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_OOB_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_OOB_PROTECTION]

//>> GET_[NET_CTRL0_OOB_PROTECTION]
static inline bool GET_NET_CTRL0_OOB_PROTECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_OOB_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_OOB_PROTECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_OOB_PROTECTION]

//>> SET_[NET_CTRL0_PLLFORCE_OUT_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLLFORCE_OUT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PLLFORCE_OUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access NET_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLLFORCE_OUT_EN]

//>> SET_[NET_CTRL0_PLLFORCE_OUT_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLLFORCE_OUT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL0_PLLFORCE_OUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access NET_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLLFORCE_OUT_EN]

//>> SET_[NET_CTRL0_PLLFORCE_OUT_EN]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL0_PLLFORCE_OUT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL0_PLLFORCE_OUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access NET_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL0_PLLFORCE_OUT_EN]

//>> CLEAR_[NET_CTRL0_PLLFORCE_OUT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL0_PLLFORCE_OUT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL0_PLLFORCE_OUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access NET_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL0_PLLFORCE_OUT_EN]

//>> GET_[NET_CTRL0_PLLFORCE_OUT_EN]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL0_PLLFORCE_OUT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL0_PLLFORCE_OUT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access NET_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PLLFORCE_OUT_EN]

//>> GET_[NET_CTRL0_PLLFORCE_OUT_EN]
static inline bool GET_NET_CTRL0_PLLFORCE_OUT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL0_RW, NET_CTRL0_RW_WAND, NET_CTRL0_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL0_PLLFORCE_OUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access NET_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL0_PLLFORCE_OUT_EN]

//>> PREP_[PLL_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PLL_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PLL_LOCK_REG]

//>> GET_[PLL_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PLL_LOCK_REG;
#endif
    return fapi2::getScom(i_target, PLL_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PLL_LOCK_REG]

//>> PUT_[PLL_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PLL_LOCK_REG));
#endif
    return fapi2::putScom(i_target, PLL_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PLL_LOCK_REG]


//>> SET_[PLL_LOCK_REG_LOCK]
static inline fapi2::buffer<uint64_t>& SET_PLL_LOCK_REG_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PLL_LOCK_REG));
#endif
    return o_data.insertFromRight<PLL_LOCK_REG_LOCK,
           PLL_LOCK_REG_LOCK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PLL_LOCK_REG_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PLL_LOCK_REG_LOCK]

//>> SET_[PLL_LOCK_REG_LOCK]
static inline fapi2::buffer<uint64_t>& SET_PLL_LOCK_REG_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PLL_LOCK_REG));
#endif
    return o_data.insertFromRight<PLL_LOCK_REG_LOCK,
           PLL_LOCK_REG_LOCK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PLL_LOCK_REG_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PLL_LOCK_REG_LOCK]

//>> GET_[PLL_LOCK_REG_LOCK]
static inline fapi2::buffer<uint64_t>& GET_PLL_LOCK_REG_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PLL_LOCK_REG));
#endif
    return i_data.extractToRight<PLL_LOCK_REG_LOCK,
           PLL_LOCK_REG_LOCK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PLL_LOCK_REG_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PLL_LOCK_REG_LOCK]

//>> PREP_[SPATTN_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SPATTN_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SPATTN_MASK_RW]

//>> GET_[SPATTN_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SPATTN_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_RW;
#endif
    return fapi2::getScom(i_target, SPATTN_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SPATTN_MASK_RW]

//>> PUT_[SPATTN_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SPATTN_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, SPATTN_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SPATTN_MASK_RW]

//>> PREP_[SPATTN_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SPATTN_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SPATTN_MASK_WO_CLEAR]

//>> GET_[SPATTN_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SPATTN_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, SPATTN_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SPATTN_MASK_WO_CLEAR]

//>> PUT_[SPATTN_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SPATTN_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, SPATTN_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SPATTN_MASK_WO_CLEAR]

//>> PREP_[SPATTN_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SPATTN_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SPATTN_MASK_WO_OR]

//>> GET_[SPATTN_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SPATTN_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, SPATTN_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SPATTN_MASK_WO_OR]

//>> PUT_[SPATTN_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SPATTN_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, SPATTN_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SPATTN_MASK_WO_OR]


//>> SET_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_01]

//>> SET_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_01]

//>> SET_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_01]

//>> CLEAR_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_01]

//>> GET_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_01]

//>> GET_[SPATTN_MASK_01]
static inline bool GET_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_01]

//>> SET_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_02]

//>> SET_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_02]

//>> SET_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_02]

//>> CLEAR_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_02]

//>> GET_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_02]

//>> GET_[SPATTN_MASK_02]
static inline bool GET_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_02]

//>> SET_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_03]

//>> SET_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_03]

//>> SET_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_03]

//>> CLEAR_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_03]

//>> GET_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_03]

//>> GET_[SPATTN_MASK_03]
static inline bool GET_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_03]

//>> SET_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_04]

//>> SET_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_04]

//>> SET_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_04]

//>> CLEAR_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_04]

//>> GET_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_04]

//>> GET_[SPATTN_MASK_04]
static inline bool GET_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_04]

//>> SET_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_05]

//>> SET_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_05]

//>> SET_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_05]

//>> CLEAR_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_05]

//>> GET_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_05]

//>> GET_[SPATTN_MASK_05]
static inline bool GET_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_05]

//>> SET_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_06]

//>> SET_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_06]

//>> SET_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_06]

//>> CLEAR_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_06]

//>> GET_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_06]

//>> GET_[SPATTN_MASK_06]
static inline bool GET_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_06]

//>> SET_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_07]

//>> SET_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_07]

//>> SET_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_07]

//>> CLEAR_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_07]

//>> GET_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_07]

//>> GET_[SPATTN_MASK_07]
static inline bool GET_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_07]

//>> SET_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_08]

//>> SET_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_08]

//>> SET_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_08]

//>> CLEAR_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_08]

//>> GET_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_08]

//>> GET_[SPATTN_MASK_08]
static inline bool GET_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_08]

//>> SET_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_09]

//>> SET_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_09]

//>> SET_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_09]

//>> CLEAR_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_09]

//>> GET_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_09]

//>> GET_[SPATTN_MASK_09]
static inline bool GET_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_09]

//>> SET_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_10]

//>> SET_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_10]

//>> SET_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_10]

//>> CLEAR_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_10]

//>> GET_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_10]

//>> GET_[SPATTN_MASK_10]
static inline bool GET_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_10]

//>> SET_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_11]

//>> SET_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_11]

//>> SET_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_11]

//>> CLEAR_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_11]

//>> GET_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_11]

//>> GET_[SPATTN_MASK_11]
static inline bool GET_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_11]

//>> SET_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_12]

//>> SET_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_12]

//>> SET_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_12]

//>> CLEAR_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_12]

//>> GET_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_12]

//>> GET_[SPATTN_MASK_12]
static inline bool GET_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_12]

//>> SET_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_13]

//>> SET_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_13]

//>> SET_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_13]

//>> CLEAR_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_13]

//>> GET_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_13]

//>> GET_[SPATTN_MASK_13]
static inline bool GET_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_13]

//>> SET_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_14]

//>> SET_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_14]

//>> SET_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_14]

//>> CLEAR_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_14]

//>> GET_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_14]

//>> GET_[SPATTN_MASK_14]
static inline bool GET_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_14]

//>> SET_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_15]

//>> SET_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_15]

//>> SET_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_15]

//>> CLEAR_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_15]

//>> GET_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_15]

//>> GET_[SPATTN_MASK_15]
static inline bool GET_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_15]

//>> SET_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_16]

//>> SET_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_16]

//>> SET_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_16]

//>> CLEAR_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_16]

//>> GET_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_16]

//>> GET_[SPATTN_MASK_16]
static inline bool GET_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_16]

//>> SET_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_17]

//>> SET_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_17]

//>> SET_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_17]

//>> CLEAR_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_17]

//>> GET_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_17]

//>> GET_[SPATTN_MASK_17]
static inline bool GET_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_17]

//>> SET_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_18]

//>> SET_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_18]

//>> SET_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_18]

//>> CLEAR_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_18]

//>> GET_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_18]

//>> GET_[SPATTN_MASK_18]
static inline bool GET_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_18]

//>> SET_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_19]

//>> SET_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_19]

//>> SET_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_19]

//>> CLEAR_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_19]

//>> GET_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_19]

//>> GET_[SPATTN_MASK_19]
static inline bool GET_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_19]

//>> SET_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_20]

//>> SET_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_20]

//>> SET_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_20]

//>> CLEAR_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_20]

//>> GET_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_20]

//>> GET_[SPATTN_MASK_20]
static inline bool GET_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_20]

//>> SET_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_21]

//>> SET_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_21]

//>> SET_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_21]

//>> CLEAR_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_21]

//>> GET_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_21]

//>> GET_[SPATTN_MASK_21]
static inline bool GET_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_21]

//>> SET_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_22]

//>> SET_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_22]

//>> SET_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_22]

//>> CLEAR_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_22]

//>> GET_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_22]

//>> GET_[SPATTN_MASK_22]
static inline bool GET_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_22]

//>> SET_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_23]

//>> SET_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_23]

//>> SET_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_23]

//>> CLEAR_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_23]

//>> GET_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_23]

//>> GET_[SPATTN_MASK_23]
static inline bool GET_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_23]

//>> SET_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_24]

//>> SET_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_24]

//>> SET_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_24]

//>> CLEAR_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_24]

//>> GET_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_24]

//>> GET_[SPATTN_MASK_24]
static inline bool GET_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_24]

//>> SET_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_25]

//>> SET_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_25]

//>> SET_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_25]

//>> CLEAR_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_25]

//>> GET_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_25]

//>> GET_[SPATTN_MASK_25]
static inline bool GET_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_25]

//>> SET_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_26]

//>> SET_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_26]

//>> SET_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_26]

//>> CLEAR_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_26]

//>> GET_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_26]

//>> GET_[SPATTN_MASK_26]
static inline bool GET_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_26]

//>> SET_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_27]

//>> SET_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_27]

//>> SET_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_27]

//>> CLEAR_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_27]

//>> GET_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_27]

//>> GET_[SPATTN_MASK_27]
static inline bool GET_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_27]

//>> SET_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_28]

//>> SET_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_28]

//>> SET_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_28]

//>> CLEAR_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_28]

//>> GET_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_28]

//>> GET_[SPATTN_MASK_28]
static inline bool GET_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_28]

//>> SET_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_29]

//>> SET_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_29]

//>> SET_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_29]

//>> CLEAR_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_29]

//>> GET_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_29]

//>> GET_[SPATTN_MASK_29]
static inline bool GET_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_29]

//>> SET_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_30]

//>> SET_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_30]

//>> SET_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_30]

//>> CLEAR_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_30]

//>> GET_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_30]

//>> GET_[SPATTN_MASK_30]
static inline bool GET_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_30]

//>> SET_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_31]

//>> SET_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_31]

//>> SET_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_31]

//>> CLEAR_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_31]

//>> GET_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_31]

//>> GET_[SPATTN_MASK_31]
static inline bool GET_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_31]

//>> SET_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_32]

//>> SET_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_32]

//>> SET_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_32]

//>> CLEAR_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_32]

//>> GET_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_32]

//>> GET_[SPATTN_MASK_32]
static inline bool GET_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_32]

//>> SET_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_33]

//>> SET_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_33]

//>> SET_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_33]

//>> CLEAR_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_33]

//>> GET_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_33]

//>> GET_[SPATTN_MASK_33]
static inline bool GET_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_33]

//>> SET_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_34]

//>> SET_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_34]

//>> SET_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_34]

//>> CLEAR_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_34]

//>> GET_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_34]

//>> GET_[SPATTN_MASK_34]
static inline bool GET_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_34]

//>> SET_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_35]

//>> SET_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_35]

//>> SET_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_35]

//>> CLEAR_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_35]

//>> GET_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_35]

//>> GET_[SPATTN_MASK_35]
static inline bool GET_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_35]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
