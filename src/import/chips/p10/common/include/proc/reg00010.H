/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00010.H $         */
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

#ifndef __PROC_REG00010_H_
#define __PROC_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_CQ_TTT_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_TTT_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_TTT_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_CQ_TTT_0]

//>> GET_[INT_CQ_TTT_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_TTT_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_TTT_0;
#endif
    return fapi2::getScom(i_target, INT_CQ_TTT_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_CQ_TTT_0]

//>> PUT_[INT_CQ_TTT_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_TTT_0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return fapi2::putScom(i_target, INT_CQ_TTT_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_CQ_TTT_0]


//>> SET_[INT_CQ_TTT_0_VALID_0_7]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_VALID_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_VALID_0_7,
           INT_CQ_TTT_0_VALID_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_VALID_0_7]

//>> SET_[INT_CQ_TTT_0_VALID_0_7]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_VALID_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_VALID_0_7,
           INT_CQ_TTT_0_VALID_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_VALID_0_7]

//>> GET_[INT_CQ_TTT_0_VALID_0_7]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_VALID_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_VALID_0_7,
           INT_CQ_TTT_0_VALID_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_VALID_0_7]

//>> SET_[INT_CQ_TTT_0_ENTRY_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_0_3,
           INT_CQ_TTT_0_ENTRY_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_0_3,
           INT_CQ_TTT_0_ENTRY_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_0_3]

//>> GET_[INT_CQ_TTT_0_ENTRY_0_3]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_ENTRY_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_ENTRY_0_3,
           INT_CQ_TTT_0_ENTRY_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_ENTRY_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_1_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_1_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_1_0_3,
           INT_CQ_TTT_0_ENTRY_1_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_1_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_1_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_1_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_1_0_3,
           INT_CQ_TTT_0_ENTRY_1_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_1_0_3]

//>> GET_[INT_CQ_TTT_0_ENTRY_1_0_3]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_ENTRY_1_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_ENTRY_1_0_3,
           INT_CQ_TTT_0_ENTRY_1_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_ENTRY_1_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_2_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_2_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_2_0_3,
           INT_CQ_TTT_0_ENTRY_2_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_2_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_2_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_2_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_2_0_3,
           INT_CQ_TTT_0_ENTRY_2_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_2_0_3]

//>> GET_[INT_CQ_TTT_0_ENTRY_2_0_3]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_ENTRY_2_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_ENTRY_2_0_3,
           INT_CQ_TTT_0_ENTRY_2_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_ENTRY_2_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_3_0]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_3_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_3_0,
           INT_CQ_TTT_0_ENTRY_3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_3_0]

//>> SET_[INT_CQ_TTT_0_ENTRY_3_0]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_3_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_3_0,
           INT_CQ_TTT_0_ENTRY_3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_3_0]

//>> GET_[INT_CQ_TTT_0_ENTRY_3_0]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_ENTRY_3_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_ENTRY_3_0,
           INT_CQ_TTT_0_ENTRY_3_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_ENTRY_3_0]

//>> SET_[INT_CQ_TTT_0_ENTRY_4_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_4_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_4_0_3,
           INT_CQ_TTT_0_ENTRY_4_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_4_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_4_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_4_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_4_0_3,
           INT_CQ_TTT_0_ENTRY_4_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_4_0_3]

//>> GET_[INT_CQ_TTT_0_ENTRY_4_0_3]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_ENTRY_4_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_ENTRY_4_0_3,
           INT_CQ_TTT_0_ENTRY_4_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_ENTRY_4_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_5_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_5_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_5_0_3,
           INT_CQ_TTT_0_ENTRY_5_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_5_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_5_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_5_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_5_0_3,
           INT_CQ_TTT_0_ENTRY_5_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_5_0_3]

//>> GET_[INT_CQ_TTT_0_ENTRY_5_0_3]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_ENTRY_5_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_ENTRY_5_0_3,
           INT_CQ_TTT_0_ENTRY_5_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_ENTRY_5_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_6_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_6_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_6_0_3,
           INT_CQ_TTT_0_ENTRY_6_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_6_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_6_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_6_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_6_0_3,
           INT_CQ_TTT_0_ENTRY_6_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_6_0_3]

//>> GET_[INT_CQ_TTT_0_ENTRY_6_0_3]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_ENTRY_6_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_ENTRY_6_0_3,
           INT_CQ_TTT_0_ENTRY_6_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_ENTRY_6_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_7_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_7_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_7_0_3,
           INT_CQ_TTT_0_ENTRY_7_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_7_0_3]

//>> SET_[INT_CQ_TTT_0_ENTRY_7_0_3]
static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_0_ENTRY_7_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_0_ENTRY_7_0_3,
           INT_CQ_TTT_0_ENTRY_7_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_CQ_TTT_0_ENTRY_7_0_3]

//>> GET_[INT_CQ_TTT_0_ENTRY_7_0_3]
static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_0_ENTRY_7_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_0));
#endif
    return i_data.extractToRight<INT_CQ_TTT_0_ENTRY_7_0_3,
           INT_CQ_TTT_0_ENTRY_7_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_CQ_TTT_0_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_CQ_TTT_0_ENTRY_7_0_3]

//>> PREP_[PB_COM_SCOM_ES3_EXTFIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_EXTFIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_EXTFIR_REG_RW]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_EXTFIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_EXTFIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_RW]

//>> PUT_[PB_COM_SCOM_ES3_EXTFIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_EXTFIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_EXTFIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_EXTFIR_REG_RW]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_0_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_1_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_2_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_3_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_4_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_5_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_6_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_7_FIR_ERR]

//>> PREP_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND]

//>> PUT_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND]

//>> PREP_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR]

//>> PUT_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_REG_RW, PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_EXTFIR_REG_WO_OR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
