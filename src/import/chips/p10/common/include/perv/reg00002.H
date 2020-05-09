/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00002.H $         */
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

#ifndef __PERV_REG00002_H_
#define __PERV_REG00002_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS]

//>> PUT_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS]


//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline bool GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]

//>> SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]

//>> GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]

//>> PREP_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]

//>> PUT_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE]


//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return o_data.setBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]

//>> CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return o_data.clearBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]
static inline bool GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return i_data.getBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE,
           CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE]

//>> PREP_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE]

//>> PUT_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE]


//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.setBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]

//>> CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.clearBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]
static inline bool GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.getBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SINGLE_STEP_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.setBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]

//>> CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.clearBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]
static inline bool GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.getBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ONE_SHOT_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.setBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]

//>> CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.clearBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]
static inline bool GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.getBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_ADJUST_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.setBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]

//>> CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.clearBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]
static inline bool GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.getBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_HOLD_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]

//>> SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.setBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]

//>> CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return o_data.clearBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.extractToRight<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]

//>> GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]
static inline bool GET_CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE));
#endif
    return i_data.getBit<CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_INIT_MD_SET]

//>> PREP_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE]

//>> GET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE]

//>> PUT_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE]


//>> SET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]

//>> SET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]

//>> SET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE));
#endif
    return o_data.setBit<CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]

//>> CLEAR_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE));
#endif
    return o_data.clearBit<CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]

//>> GET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE));
#endif
    return i_data.extractToRight<CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]

//>> GET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]
static inline bool GET_CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE));
#endif
    return i_data.getBit<CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1]

//>> PREP_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES]

//>> GET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES]

//>> PUT_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES]


//>> SET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE,
           CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE]

//>> SET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE,
           CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE]

//>> GET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return i_data.extractToRight<CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE,
           CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE]

//>> SET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE,
           CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE]

//>> SET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE,
           CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE]

//>> GET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES));
#endif
    return i_data.extractToRight<CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE,
           CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE]

//>> PREP_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE]

//>> PUT_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE]


//>> SET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD]

//>> PREP_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS]

//>> PUT_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS]


//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.setBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.clearBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]
static inline bool GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.getBit<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]

//>> SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]

//>> GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS));
#endif
    return i_data.extractToRight<CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG,
           CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG]

//>> PREP_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES]

//>> PUT_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES]


//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return i_data.extractToRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return i_data.extractToRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return i_data.extractToRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES));
#endif
    return i_data.extractToRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3]

//>> PREP_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]

//>> PUT_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE]


//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE));
#endif
    return o_data.setBit<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]

//>> CLEAR_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]
static inline fapi2::buffer<uint64_t>&
CLEAR_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE));
#endif
    return o_data.clearBit<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE));
#endif
    return i_data.extractToRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]
static inline bool GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE));
#endif
    return i_data.getBit<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK]

//>> PREP_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC]

//>> PUT_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC]


//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC));
#endif
    return o_data.setBit<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]

//>> CLEAR_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC));
#endif
    return o_data.clearBit<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC));
#endif
    return i_data.extractToRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]
static inline bool GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC));
#endif
    return i_data.getBit<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT]

//>> PREP_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]

//>> PUT_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT]


//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE]

//>> SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT));
#endif
    return o_data.insertFromRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE]

//>> GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT));
#endif
    return i_data.extractToRight<CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE,
           CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE]

//>> PREP_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG;
#endif
    return fapi2::getScom(i_target, CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG]

//>> PUT_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return fapi2::putScom(i_target, CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG]


//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]

//>> CLEAR_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]
static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]

//>> CLEAR_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]
static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]

//>> CLEAR_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]
static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.insertFromRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]

//>> SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]
static inline fapi2::buffer<uint64_t>& SET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.setBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]

//>> CLEAR_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return o_data.clearBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]
static inline fapi2::buffer<uint64_t>& GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.extractToRight<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]

//>> GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]
static inline bool GET_CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG));
#endif
    return i_data.getBit<CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE]

//>> PREP_[DBG_CBS_CC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DBG_CBS_CC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DBG_CBS_CC]

//>> GET_[DBG_CBS_CC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DBG_CBS_CC;
#endif
    return fapi2::getScom(i_target, DBG_CBS_CC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DBG_CBS_CC]

//>> PUT_[DBG_CBS_CC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return fapi2::putScom(i_target, DBG_CBS_CC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DBG_CBS_CC]


//>> SET_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_RESET_EP]

//>> SET_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_RESET_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_RESET_EP]

//>> SET_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_RESET_EP]

//>> CLEAR_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_RESET_EP]

//>> GET_[DBG_CBS_CC_DBG_RESET_EP]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_RESET_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_RESET_EP]

//>> GET_[DBG_CBS_CC_DBG_RESET_EP]
static inline bool GET_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_RESET_EP]

//>> SET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> SET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_OPCG_IP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> SET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> CLEAR_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_OPCG_IP]

//>> GET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_OPCG_IP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> GET_[DBG_CBS_CC_DBG_OPCG_IP]
static inline bool GET_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_OPCG_IP]

//>> SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_VITL_CLKOFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> CLEAR_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> GET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> GET_[DBG_CBS_CC_DBG_VITL_CLKOFF]
static inline bool GET_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_VITL_CLKOFF]

//>> SET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> SET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_TEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> SET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> CLEAR_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> GET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> GET_[DBG_CBS_CC_DBG_TEST_ENABLE]
static inline bool GET_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_TEST_ENABLE]

//>> SET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> SET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> SET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> CLEAR_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_CBS_REQ]

//>> GET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> GET_[DBG_CBS_CC_DBG_CBS_REQ]
static inline bool GET_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_REQ]

//>> SET_[DBG_CBS_CC_DBG_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_CMD,
           DBG_CBS_CC_DBG_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_CMD]

//>> SET_[DBG_CBS_CC_DBG_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_CMD,
           DBG_CBS_CC_DBG_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_CMD]

//>> GET_[DBG_CBS_CC_DBG_CBS_CMD]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CBS_CMD,
           DBG_CBS_CC_DBG_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_CMD]

//>> SET_[DBG_CBS_CC_DBG_CBS_STATE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_STATE,
           DBG_CBS_CC_DBG_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_STATE]

//>> SET_[DBG_CBS_CC_DBG_CBS_STATE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_STATE,
           DBG_CBS_CC_DBG_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_STATE]

//>> GET_[DBG_CBS_CC_DBG_CBS_STATE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CBS_STATE,
           DBG_CBS_CC_DBG_CBS_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_STATE]

//>> SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> CLEAR_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> GET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> GET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]
static inline bool GET_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE]

//>> SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> CLEAR_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> GET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> GET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]
static inline bool GET_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> SET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> SET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> CLEAR_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> GET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PCB_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> GET_[DBG_CBS_CC_DBG_PCB_IDLE]
static inline bool GET_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_IDLE]

//>> SET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]

//>> SET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]

//>> GET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CURRENT_OPCG_MODE]

//>> SET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]

//>> SET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_LAST_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]

//>> GET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_LAST_OPCG_MODE]

//>> SET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> CLEAR_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> GET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PCB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> GET_[DBG_CBS_CC_DBG_PCB_ERROR]
static inline bool GET_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> SET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> CLEAR_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> GET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> GET_[DBG_CBS_CC_DBG_PARITY_ERROR]
static inline bool GET_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARITY_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> CLEAR_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_CC_ERROR]

//>> GET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> GET_[DBG_CBS_CC_DBG_CC_ERROR]
static inline bool GET_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CC_ERROR]

//>> SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> CLEAR_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> GET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> GET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]
static inline bool GET_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED]

//>> SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> CLEAR_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> GET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> GET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]
static inline bool GET_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> CLEAR_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> GET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> GET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]
static inline bool GET_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> CLEAR_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> GET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> GET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]
static inline bool GET_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.insertFromRight<DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.setBit<DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> CLEAR_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& CLEAR_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return o_data.clearBit<DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> GET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& GET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.extractToRight<DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> GET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]
static inline bool GET_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DBG_CBS_CC));
#endif
    return i_data.getBit<DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DBG_CBS_CC_TP_TPFSI_CBS_ACK]

//>> PREP_[EPS_PSC_ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_PSC_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_ADDR_TRAP_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_PSC_ADDR_TRAP_REG]

//>> GET_[EPS_PSC_ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_PSC_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_ADDR_TRAP_REG;
#endif
    return fapi2::getScom(i_target, EPS_PSC_ADDR_TRAP_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG]

//>> PUT_[EPS_PSC_ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_PSC_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return fapi2::putScom(i_target, EPS_PSC_ADDR_TRAP_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_PSC_ADDR_TRAP_REG]


//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.setBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.clearBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline bool GET_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.getBit<EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID,
           EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]

//>> SET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID,
           EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]

//>> GET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID,
           EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID]

//>> PREP_[EPS_PSC_PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_PSCOM_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_PSC_PSCOM_MODE_REG]

//>> GET_[EPS_PSC_PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_PSCOM_MODE_REG;
#endif
    return fapi2::getScom(i_target, EPS_PSC_PSCOM_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG]

//>> PUT_[EPS_PSC_PSCOM_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return fapi2::putScom(i_target, EPS_PSC_PSCOM_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_PSC_PSCOM_MODE_REG]


//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> CLEAR_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]
static inline bool GET_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

//>> SET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

//>> GET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT]

//>> PREP_[EPS_THERM_WSUB2_DTS_TRC_RESULT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB2_DTS_TRC_RESULT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_DTS_TRC_RESULT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB2_DTS_TRC_RESULT]

//>> GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB2_DTS_TRC_RESULT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_DTS_TRC_RESULT;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB2_DTS_TRC_RESULT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT]

//>> PUT_[EPS_THERM_WSUB2_DTS_TRC_RESULT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB2_DTS_TRC_RESULT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB2_DTS_TRC_RESULT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB2_DTS_TRC_RESULT]


//>> SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE,
           EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE]

//>> SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE,
           EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE]

//>> GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE,
           EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE]

//>> SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]

//>> SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]

//>> SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]

//>> CLEAR_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]

//>> GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]

//>> GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]
static inline bool GET_EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR]

//>> SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT,
           EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT]

//>> SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT,
           EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT]

//>> GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_TRC_RESULT));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT,
           EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT]

//>> PREP_[EPS_THERM_WSUB2_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB2_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_ERR_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB2_ERR_STATUS_REG]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB2_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_ERR_STATUS_REG;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB2_ERR_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG]

//>> PUT_[EPS_THERM_WSUB2_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB2_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB2_ERR_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB2_ERR_STATUS_REG]


//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> PREP_[EPS_THERM_WSUB2_SKITTER_DATA1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB2_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_SKITTER_DATA1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB2_SKITTER_DATA1]

//>> GET_[EPS_THERM_WSUB2_SKITTER_DATA1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB2_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_SKITTER_DATA1;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB2_SKITTER_DATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB2_SKITTER_DATA1]

//>> PUT_[EPS_THERM_WSUB2_SKITTER_DATA1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB2_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_SKITTER_DATA1));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB2_SKITTER_DATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB2_SKITTER_DATA1]


//>> PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI]

//>> GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI]

//>> PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI]

//>> PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW]

//>> GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW]

//>> PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW]


//>> SET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15]

//>> SET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15]

//>> GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15]

//>> PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI]

//>> GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI]

//>> PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI]

//>> PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW]

//>> GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW]

//>> PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW]


//>> SET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2]

//>> SET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2]

//>> GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI, FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2,
           FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2]

//>> PREP_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI]

//>> GET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI]

//>> PUT_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI]

//>> PREP_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO]

//>> GET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO]

//>> PUT_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO]


//>> SET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8]

//>> SET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8]

//>> GET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI, FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE,
                           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8,
           FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8]

//>> PREP_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI]

//>> GET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI]

//>> PUT_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI]

//>> PREP_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW]

//>> GET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW]

//>> PUT_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW]


//>> SET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11,
           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11]

//>> SET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11,
           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11]

//>> GET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI, FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11,
           FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11]

//>> PREP_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI]

//>> GET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI]

//>> PUT_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI]

//>> PREP_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO]

//>> GET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO]

//>> PUT_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO]


//>> SET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4,
           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4]

//>> SET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4,
           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4]

//>> GET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI, FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE,
                           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4,
           FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4]

//>> PREP_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI]

//>> GET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI]

//>> PUT_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI]

//>> PREP_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW]

//>> GET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW]

//>> PUT_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW]


//>> SET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A,
           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A]

//>> SET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A,
           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A]

//>> GET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A,
           FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A]

//>> PREP_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI]

//>> GET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI]

//>> PUT_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI]

//>> PREP_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO]

//>> GET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO]

//>> PUT_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO]


//>> SET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B]
static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B,
           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B]

//>> SET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B]
static inline fapi2::buffer<uint64_t>&
SET_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B,
           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B]

//>> GET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B]
static inline fapi2::buffer<uint64_t>&
GET_FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI,
                           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE, FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B,
           FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW]


//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3]

//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3]

//>> PREP_[HEARTBEAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_HEARTBEAT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HEARTBEAT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[HEARTBEAT_REG]

//>> GET_[HEARTBEAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_HEARTBEAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HEARTBEAT_REG;
#endif
    return fapi2::getScom(i_target, HEARTBEAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[HEARTBEAT_REG]

//>> PUT_[HEARTBEAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_HEARTBEAT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return fapi2::putScom(i_target, HEARTBEAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[HEARTBEAT_REG]


//>> SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& SET_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return o_data.insertFromRight<HEARTBEAT_REG_HEARTBEAT_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& SET_HEARTBEAT_REG_HEARTBEAT_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return o_data.insertFromRight<HEARTBEAT_REG_HEARTBEAT_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& SET_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return o_data.setBit<HEARTBEAT_REG_HEARTBEAT_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> CLEAR_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return o_data.clearBit<HEARTBEAT_REG_HEARTBEAT_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> GET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline fapi2::buffer<uint64_t>& GET_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return i_data.extractToRight<HEARTBEAT_REG_HEARTBEAT_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> GET_[HEARTBEAT_REG_HEARTBEAT_DEAD]
static inline bool GET_HEARTBEAT_REG_HEARTBEAT_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HEARTBEAT_REG));
#endif
    return i_data.getBit<HEARTBEAT_REG_HEARTBEAT_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access HEARTBEAT_REG_HEARTBEAT_DEAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HEARTBEAT_REG_HEARTBEAT_DEAD]

//>> PREP_[L3TRA0_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3TRA0_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA0_TR1_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3TRA0_TR1_CONFIG_2]

//>> GET_[L3TRA0_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3TRA0_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA0_TR1_CONFIG_2;
#endif
    return fapi2::getScom(i_target, L3TRA0_TR1_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3TRA0_TR1_CONFIG_2]

//>> PUT_[L3TRA0_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3TRA0_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_2));
#endif
    return fapi2::putScom(i_target, L3TRA0_TR1_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3TRA0_TR1_CONFIG_2]


//>> SET_[L3TRA0_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_2_A,
           L3TRA0_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access L3TRA0_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA0_TR1_CONFIG_2_A]

//>> SET_[L3TRA0_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_2_A,
           L3TRA0_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access L3TRA0_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA0_TR1_CONFIG_2_A]

//>> GET_[L3TRA0_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_2_A,
           L3TRA0_TR1_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access L3TRA0_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3TRA0_TR1_CONFIG_2_A]

//>> SET_[L3TRA0_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_2_B,
           L3TRA0_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access L3TRA0_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA0_TR1_CONFIG_2_B]

//>> SET_[L3TRA0_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_L3TRA0_TR1_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<L3TRA0_TR1_CONFIG_2_B,
           L3TRA0_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access L3TRA0_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA0_TR1_CONFIG_2_B]

//>> GET_[L3TRA0_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& GET_L3TRA0_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA0_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<L3TRA0_TR1_CONFIG_2_B,
           L3TRA0_TR1_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access L3TRA0_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3TRA0_TR1_CONFIG_2_B]

//>> PREP_[L3TRA1_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3TRA1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA1_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3TRA1_TR0_CONFIG_4]

//>> GET_[L3TRA1_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3TRA1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA1_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, L3TRA1_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3TRA1_TR0_CONFIG_4]

//>> PUT_[L3TRA1_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3TRA1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3TRA1_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, L3TRA1_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3TRA1_TR0_CONFIG_4]


//>> SET_[L3TRA1_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_L3TRA1_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<L3TRA1_TR0_CONFIG_4_A,
           L3TRA1_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access L3TRA1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA1_TR0_CONFIG_4_A]

//>> SET_[L3TRA1_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_L3TRA1_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<L3TRA1_TR0_CONFIG_4_A,
           L3TRA1_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access L3TRA1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA1_TR0_CONFIG_4_A]

//>> GET_[L3TRA1_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& GET_L3TRA1_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA1_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<L3TRA1_TR0_CONFIG_4_A,
           L3TRA1_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access L3TRA1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3TRA1_TR0_CONFIG_4_A]

//>> SET_[L3TRA1_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_L3TRA1_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<L3TRA1_TR0_CONFIG_4_B,
           L3TRA1_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access L3TRA1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA1_TR0_CONFIG_4_B]

//>> SET_[L3TRA1_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_L3TRA1_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<L3TRA1_TR0_CONFIG_4_B,
           L3TRA1_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access L3TRA1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA1_TR0_CONFIG_4_B]

//>> GET_[L3TRA1_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& GET_L3TRA1_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA1_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<L3TRA1_TR0_CONFIG_4_B,
           L3TRA1_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access L3TRA1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3TRA1_TR0_CONFIG_4_B]

//>> PREP_[L3TRA2_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3TRA2_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA2_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3TRA2_TR0_CONFIG_3]

//>> GET_[L3TRA2_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3TRA2_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA2_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, L3TRA2_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3TRA2_TR0_CONFIG_3]

//>> PUT_[L3TRA2_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3TRA2_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3TRA2_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, L3TRA2_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3TRA2_TR0_CONFIG_3]


//>> SET_[L3TRA2_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_L3TRA2_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<L3TRA2_TR0_CONFIG_3_C,
           L3TRA2_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access L3TRA2_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA2_TR0_CONFIG_3_C]

//>> SET_[L3TRA2_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_L3TRA2_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<L3TRA2_TR0_CONFIG_3_C,
           L3TRA2_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access L3TRA2_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA2_TR0_CONFIG_3_C]

//>> GET_[L3TRA2_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& GET_L3TRA2_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<L3TRA2_TR0_CONFIG_3_C,
           L3TRA2_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access L3TRA2_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3TRA2_TR0_CONFIG_3_C]

//>> SET_[L3TRA2_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_L3TRA2_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<L3TRA2_TR0_CONFIG_3_D,
           L3TRA2_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access L3TRA2_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA2_TR0_CONFIG_3_D]

//>> SET_[L3TRA2_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_L3TRA2_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<L3TRA2_TR0_CONFIG_3_D,
           L3TRA2_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access L3TRA2_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA2_TR0_CONFIG_3_D]

//>> GET_[L3TRA2_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& GET_L3TRA2_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA2_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<L3TRA2_TR0_CONFIG_3_D,
           L3TRA2_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access L3TRA2_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3TRA2_TR0_CONFIG_3_D]

//>> PREP_[L3TRA3_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3TRA3_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA3_TR1_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3TRA3_TR1_CONFIG_5]

//>> GET_[L3TRA3_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3TRA3_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3TRA3_TR1_CONFIG_5;
#endif
    return fapi2::getScom(i_target, L3TRA3_TR1_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3TRA3_TR1_CONFIG_5]

//>> PUT_[L3TRA3_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3TRA3_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3TRA3_TR1_CONFIG_5));
#endif
    return fapi2::putScom(i_target, L3TRA3_TR1_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3TRA3_TR1_CONFIG_5]


//>> SET_[L3TRA3_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_L3TRA3_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA3_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<L3TRA3_TR1_CONFIG_5_C,
           L3TRA3_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access L3TRA3_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA3_TR1_CONFIG_5_C]

//>> SET_[L3TRA3_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_L3TRA3_TR1_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA3_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<L3TRA3_TR1_CONFIG_5_C,
           L3TRA3_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access L3TRA3_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA3_TR1_CONFIG_5_C]

//>> GET_[L3TRA3_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& GET_L3TRA3_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA3_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<L3TRA3_TR1_CONFIG_5_C,
           L3TRA3_TR1_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access L3TRA3_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3TRA3_TR1_CONFIG_5_C]

//>> SET_[L3TRA3_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_L3TRA3_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA3_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<L3TRA3_TR1_CONFIG_5_D,
           L3TRA3_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access L3TRA3_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA3_TR1_CONFIG_5_D]

//>> SET_[L3TRA3_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_L3TRA3_TR1_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA3_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<L3TRA3_TR1_CONFIG_5_D,
           L3TRA3_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access L3TRA3_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3TRA3_TR1_CONFIG_5_D]

//>> GET_[L3TRA3_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& GET_L3TRA3_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3TRA3_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<L3TRA3_TR1_CONFIG_5_D,
           L3TRA3_TR1_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access L3TRA3_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3TRA3_TR1_CONFIG_5_D]

//>> PREP_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_CAPT3]

//>> GET_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT3;
#endif
    return fapi2::getScom(i_target, OPCG_CAPT3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_CAPT3]

//>> PUT_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return fapi2::putScom(i_target, OPCG_CAPT3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_CAPT3]


//>> SET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07EVEN]

//>> SET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07EVEN]

//>> GET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_07EVEN]

//>> SET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07ODD]

//>> SET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07ODD]

//>> GET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_07ODD]

//>> SET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08EVEN]

//>> SET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08EVEN]

//>> GET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_08EVEN]

//>> SET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08ODD]

//>> SET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08ODD]

//>> GET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_08ODD]

//>> SET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09EVEN]

//>> SET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09EVEN]

//>> GET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_09EVEN]

//>> SET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09ODD]

//>> SET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09ODD]

//>> GET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_09ODD]

//>> SET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10EVEN]

//>> SET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10EVEN]

//>> GET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_10EVEN]

//>> SET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10ODD]

//>> SET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10ODD]

//>> GET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_10ODD]

//>> SET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11EVEN]

//>> SET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11EVEN]

//>> GET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_11EVEN]

//>> SET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11ODD]

//>> SET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11ODD]

//>> GET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_11ODD]

//>> SET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12EVEN]

//>> SET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12EVEN]

//>> GET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_12EVEN]

//>> SET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12ODD]

//>> SET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12ODD]

//>> GET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_12ODD]

//>> PREP_[OTPC_M_MEASURE_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTPC_M_MEASURE_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_MEASURE_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OTPC_M_MEASURE_REG2]

//>> GET_[OTPC_M_MEASURE_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTPC_M_MEASURE_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OTPC_M_MEASURE_REG2;
#endif
    return fapi2::getScom(i_target, OTPC_M_MEASURE_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OTPC_M_MEASURE_REG2]

//>> PUT_[OTPC_M_MEASURE_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTPC_M_MEASURE_REG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG2));
#endif
    return fapi2::putScom(i_target, OTPC_M_MEASURE_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OTPC_M_MEASURE_REG2]


//>> SET_[OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG2));
#endif
    return o_data.insertFromRight<OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA,
           OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA]

//>> SET_[OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA]
static inline fapi2::buffer<uint64_t>& SET_OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG2));
#endif
    return o_data.insertFromRight<OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA,
           OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA]

//>> GET_[OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA]
static inline fapi2::buffer<uint64_t>& GET_OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OTPC_M_MEASURE_REG2));
#endif
    return i_data.extractToRight<OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA,
           OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA]

//>> PREP_[QMETRA0_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QMETRA0_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QMETRA0_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QMETRA0_TR0_CONFIG_2]

//>> GET_[QMETRA0_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QMETRA0_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QMETRA0_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, QMETRA0_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QMETRA0_TR0_CONFIG_2]

//>> PUT_[QMETRA0_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QMETRA0_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, QMETRA0_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QMETRA0_TR0_CONFIG_2]


//>> SET_[QMETRA0_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_2_A,
           QMETRA0_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access QMETRA0_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QMETRA0_TR0_CONFIG_2_A]

//>> SET_[QMETRA0_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_2_A,
           QMETRA0_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access QMETRA0_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QMETRA0_TR0_CONFIG_2_A]

//>> GET_[QMETRA0_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_2_A,
           QMETRA0_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access QMETRA0_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QMETRA0_TR0_CONFIG_2_A]

//>> SET_[QMETRA0_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_2_B,
           QMETRA0_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access QMETRA0_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QMETRA0_TR0_CONFIG_2_B]

//>> SET_[QMETRA0_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_QMETRA0_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<QMETRA0_TR0_CONFIG_2_B,
           QMETRA0_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access QMETRA0_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QMETRA0_TR0_CONFIG_2_B]

//>> GET_[QMETRA0_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& GET_QMETRA0_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QMETRA0_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<QMETRA0_TR0_CONFIG_2_B,
           QMETRA0_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access QMETRA0_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QMETRA0_TR0_CONFIG_2_B]

//>> PREP_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RECOV_INTERRUPT_REG]

//>> GET_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, RECOV_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG]

//>> PUT_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, RECOV_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RECOV_INTERRUPT_REG]


//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<RECOV_INTERRUPT_REG_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<RECOV_INTERRUPT_REG_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.setBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> CLEAR_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.clearBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_INTERRUPT_REG_RECOV]

//>> GET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& GET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return i_data.extractToRight<RECOV_INTERRUPT_REG_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG_RECOV]

//>> GET_[RECOV_INTERRUPT_REG_RECOV]
static inline bool GET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return i_data.getBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG_RECOV]

//>> PREP_[REC_ERR_MST4_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_MST4_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST4_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REC_ERR_MST4_REG1]

//>> GET_[REC_ERR_MST4_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_MST4_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST4_REG1;
#endif
    return fapi2::getScom(i_target, REC_ERR_MST4_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REC_ERR_MST4_REG1]

//>> PUT_[REC_ERR_MST4_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_MST4_REG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return fapi2::putScom(i_target, REC_ERR_MST4_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REC_ERR_MST4_REG1]


//>> SET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_16_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_16_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_16_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_16_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_16_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_16_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_16_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_16_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_16_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_16_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_16_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_16_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_16_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_16_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_16_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_16_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_17_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_17_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_17_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_17_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_17_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_17_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_17_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_17_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_17_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_17_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_17_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_17_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_17_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_17_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_17_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_17_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_18_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_18_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_18_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_18_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_18_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_18_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_18_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_18_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_18_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_18_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_18_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_18_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_18_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_18_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_18_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_18_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_19_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_19_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_19_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_19_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_19_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_19_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_19_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_19_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_19_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_19_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_19_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_19_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_19_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_19_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_19_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_19_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_20_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_20_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_20_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_20_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_20_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_20_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_20_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_20_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_20_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_20_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_20_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_20_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_20_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_20_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_20_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_20_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_21_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_21_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_21_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_21_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_21_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_21_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_21_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_21_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_21_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_21_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_21_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_21_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_21_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_21_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_21_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_21_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_22_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_22_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_22_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_22_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_22_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_22_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_22_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_22_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_22_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_22_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_22_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_22_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_22_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_22_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_22_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_22_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_23_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_23_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_23_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_23_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_23_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_23_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_23_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_23_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_23_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_23_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_23_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_23_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_23_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_23_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_23_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_23_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_24_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_24_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_24_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_24_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_24_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_24_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_24_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_24_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_24_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_24_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_24_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_24_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_24_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_24_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_24_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_24_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_25_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_25_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_25_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_25_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_25_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_25_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_25_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_25_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_25_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_25_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_25_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_25_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_25_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_25_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_25_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_25_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_26_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_26_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_26_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_26_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_26_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_26_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_26_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_26_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_26_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_26_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_26_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_26_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_26_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_26_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_26_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_26_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_27_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_27_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_27_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_27_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_27_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_27_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_27_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_27_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_27_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_27_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_27_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_27_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_27_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_27_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_27_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_27_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_28_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_28_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_28_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_28_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_28_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_28_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_28_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_28_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_28_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_28_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_28_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_28_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_28_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_28_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_28_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_28_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_29_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_29_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_29_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_29_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_29_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_29_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_29_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_29_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_29_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_29_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_29_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_29_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_29_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_29_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_29_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_29_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_30_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_30_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_30_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_30_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_30_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_30_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_30_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_30_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_30_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_30_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_30_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_30_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_30_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_30_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_30_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_30_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.setBit<REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]

//>> GET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.getBit<REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT]

//>> SET_[REC_ERR_MST4_REG1_31_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_31_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_31_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_31_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_31_MST4_ERROR_CODE]

//>> SET_[REC_ERR_MST4_REG1_31_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST4_REG1_31_MST4_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST4_REG1_31_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_31_MST4_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST4_REG1_31_MST4_ERROR_CODE]

//>> GET_[REC_ERR_MST4_REG1_31_MST4_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST4_REG1_31_MST4_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST4_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST4_REG1_31_MST4_ERROR_CODE,
           REC_ERR_MST4_REG1_31_MST4_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST4_REG1_31_MST4_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST4_REG1_31_MST4_ERROR_CODE]

//>> PREP_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN32(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN32;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN32]

//>> GET_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN32(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN32;
#endif
    return fapi2::getScom(i_target, SCAN32, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN32]

//>> PUT_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN32(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return fapi2::putScom(i_target, SCAN32, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN32]


//>> SET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN32_SCAN32_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return o_data.insertFromRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN32_SCAN32_REG]

//>> SET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN32_SCAN32_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return o_data.insertFromRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN32_SCAN32_REG]

//>> GET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& GET_SCAN32_SCAN32_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return i_data.extractToRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN32_SCAN32_REG]

//>> PREP_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN64(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN64;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN64]

//>> GET_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN64(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN64;
#endif
    return fapi2::getScom(i_target, SCAN64, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN64]

//>> PUT_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN64(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return fapi2::putScom(i_target, SCAN64, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN64]


//>> SET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN64_SCAN64_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return o_data.insertFromRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN64_SCAN64_REG]

//>> SET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN64_SCAN64_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return o_data.insertFromRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN64_SCAN64_REG]

//>> GET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& GET_SCAN64_SCAN64_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return i_data.extractToRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN64_SCAN64_REG]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG1]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG1;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG1]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG1));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG1]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG1));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1,
           SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG1));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1,
           SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG1));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1,
           SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG100]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG100(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG100;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG100]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG100]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG100(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG100;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG100, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG100]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG100]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG100(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG100));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG100, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG100]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG100));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100,
           SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG100));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100,
           SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG100));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100,
           SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG11]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG11(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG11;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG11]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG11]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG11(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG11;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG11, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG11]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG11]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG11(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG11));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG11, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG11]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG11));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11,
           SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG11));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11,
           SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG11));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11,
           SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG26]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG26(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG26;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG26]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG26]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG26(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG26;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG26, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG26]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG26]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG26(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG26));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG26, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG26]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG26));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26,
           SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG26));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26,
           SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG26));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26,
           SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG39]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG39(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG39;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG39]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG39]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG39(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG39;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG39, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG39]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG39]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG39(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG39));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG39, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG39]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG39));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39,
           SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG39));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39,
           SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG39));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39,
           SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG47]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG47(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG47;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG47]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG47]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG47(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG47;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG47, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG47]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG47]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG47(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG47));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG47, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG47]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG47));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47,
           SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG47));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47,
           SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG47));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47,
           SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG58]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG58(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG58;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG58]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG58]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG58(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG58;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG58, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG58]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG58]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG58(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG58));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG58, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG58]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG58));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58,
           SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG58));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58,
           SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG58));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58,
           SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG70]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG70(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG70;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG70]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG70]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG70(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG70;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG70, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG70]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG70]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG70(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG70));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG70, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG70]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG70));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70,
           SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG70));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70,
           SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG70));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70,
           SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG85]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG85(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG85;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG85]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG85]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG85(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG85;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG85, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG85]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG85]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG85(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG85));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG85, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG85]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG85));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85,
           SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG85));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85,
           SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG85));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85,
           SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85]

//>> PREP_[TRA0_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA0_TR0_TRACE_HI_DATA_REG]

//>> GET_[TRA0_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA0_TR0_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA0_TR0_TRACE_HI_DATA_REG]

//>> PUT_[TRA0_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA0_TR0_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA0_TR0_TRACE_HI_DATA_REG]


//>> SET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> SET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> GET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> PREP_[TRA0_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR1_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA0_TR1_CONFIG_2]

//>> GET_[TRA0_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR1_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TRA0_TR1_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA0_TR1_CONFIG_2]

//>> PUT_[TRA0_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TRA0_TR1_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA0_TR1_CONFIG_2]


//>> SET_[TRA0_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA0_TR1_CONFIG_2_A,
           TRA0_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR1_CONFIG_2_A]

//>> SET_[TRA0_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR1_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA0_TR1_CONFIG_2_A,
           TRA0_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR1_CONFIG_2_A]

//>> GET_[TRA0_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TRA0_TR1_CONFIG_2_A,
           TRA0_TR1_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR1_CONFIG_2_A]

//>> SET_[TRA0_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA0_TR1_CONFIG_2_B,
           TRA0_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR1_CONFIG_2_B]

//>> SET_[TRA0_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR1_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA0_TR1_CONFIG_2_B,
           TRA0_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR1_CONFIG_2_B]

//>> GET_[TRA0_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TRA0_TR1_CONFIG_2_B,
           TRA0_TR1_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR1_CONFIG_2_B]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
