/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00018.H $          */
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

#ifndef __OMI_REG00018_H_
#define __OMI_REG00018_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[EDPL_MAX_COUNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EDPL_MAX_COUNT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EDPL_MAX_COUNT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EDPL_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EDPL_MAX_COUNT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EDPL_MAX_COUNT;
#endif
    return fapi2::getScom(i_target, EDPL_MAX_COUNT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EDPL_MAX_COUNT]

//>> PUT_[EDPL_MAX_COUNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EDPL_MAX_COUNT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return fapi2::putScom(i_target, EDPL_MAX_COUNT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EDPL_MAX_COUNT]


//>> SET_[EDPL_MAX_COUNT_7_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_7_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_7_MAX_COUNT,
           EDPL_MAX_COUNT_7_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access EDPL_MAX_COUNT_7_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_7_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_7_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_7_MAX_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_7_MAX_COUNT,
           EDPL_MAX_COUNT_7_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access EDPL_MAX_COUNT_7_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_7_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT_7_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EDPL_MAX_COUNT_7_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return i_data.extractToRight<EDPL_MAX_COUNT_7_MAX_COUNT,
           EDPL_MAX_COUNT_7_MAX_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access EDPL_MAX_COUNT_7_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EDPL_MAX_COUNT_7_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_6_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_6_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_6_MAX_COUNT,
           EDPL_MAX_COUNT_6_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access EDPL_MAX_COUNT_6_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_6_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_6_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_6_MAX_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_6_MAX_COUNT,
           EDPL_MAX_COUNT_6_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access EDPL_MAX_COUNT_6_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_6_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT_6_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EDPL_MAX_COUNT_6_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return i_data.extractToRight<EDPL_MAX_COUNT_6_MAX_COUNT,
           EDPL_MAX_COUNT_6_MAX_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access EDPL_MAX_COUNT_6_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EDPL_MAX_COUNT_6_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_5_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_5_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_5_MAX_COUNT,
           EDPL_MAX_COUNT_5_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access EDPL_MAX_COUNT_5_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_5_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_5_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_5_MAX_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_5_MAX_COUNT,
           EDPL_MAX_COUNT_5_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access EDPL_MAX_COUNT_5_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_5_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT_5_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EDPL_MAX_COUNT_5_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return i_data.extractToRight<EDPL_MAX_COUNT_5_MAX_COUNT,
           EDPL_MAX_COUNT_5_MAX_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access EDPL_MAX_COUNT_5_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EDPL_MAX_COUNT_5_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_4_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_4_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_4_MAX_COUNT,
           EDPL_MAX_COUNT_4_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access EDPL_MAX_COUNT_4_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_4_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_4_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_4_MAX_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_4_MAX_COUNT,
           EDPL_MAX_COUNT_4_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access EDPL_MAX_COUNT_4_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_4_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT_4_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EDPL_MAX_COUNT_4_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return i_data.extractToRight<EDPL_MAX_COUNT_4_MAX_COUNT,
           EDPL_MAX_COUNT_4_MAX_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access EDPL_MAX_COUNT_4_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EDPL_MAX_COUNT_4_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_3_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_3_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_3_MAX_COUNT,
           EDPL_MAX_COUNT_3_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access EDPL_MAX_COUNT_3_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_3_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_3_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_3_MAX_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_3_MAX_COUNT,
           EDPL_MAX_COUNT_3_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access EDPL_MAX_COUNT_3_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_3_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT_3_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EDPL_MAX_COUNT_3_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return i_data.extractToRight<EDPL_MAX_COUNT_3_MAX_COUNT,
           EDPL_MAX_COUNT_3_MAX_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access EDPL_MAX_COUNT_3_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EDPL_MAX_COUNT_3_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_2_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_2_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_2_MAX_COUNT,
           EDPL_MAX_COUNT_2_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access EDPL_MAX_COUNT_2_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_2_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_2_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_2_MAX_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_2_MAX_COUNT,
           EDPL_MAX_COUNT_2_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access EDPL_MAX_COUNT_2_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_2_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT_2_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EDPL_MAX_COUNT_2_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return i_data.extractToRight<EDPL_MAX_COUNT_2_MAX_COUNT,
           EDPL_MAX_COUNT_2_MAX_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access EDPL_MAX_COUNT_2_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EDPL_MAX_COUNT_2_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_1_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_1_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_1_MAX_COUNT,
           EDPL_MAX_COUNT_1_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access EDPL_MAX_COUNT_1_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_1_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_1_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_1_MAX_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_1_MAX_COUNT,
           EDPL_MAX_COUNT_1_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access EDPL_MAX_COUNT_1_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_1_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT_1_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EDPL_MAX_COUNT_1_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return i_data.extractToRight<EDPL_MAX_COUNT_1_MAX_COUNT,
           EDPL_MAX_COUNT_1_MAX_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access EDPL_MAX_COUNT_1_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EDPL_MAX_COUNT_1_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_0_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_0_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_0_MAX_COUNT,
           EDPL_MAX_COUNT_0_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access EDPL_MAX_COUNT_0_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_0_MAX_COUNT]

//>> SET_[EDPL_MAX_COUNT_0_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EDPL_MAX_COUNT_0_MAX_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return o_data.insertFromRight<EDPL_MAX_COUNT_0_MAX_COUNT,
           EDPL_MAX_COUNT_0_MAX_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access EDPL_MAX_COUNT_0_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EDPL_MAX_COUNT_0_MAX_COUNT]

//>> GET_[EDPL_MAX_COUNT_0_MAX_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EDPL_MAX_COUNT_0_MAX_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EDPL_MAX_COUNT));
#endif
    return i_data.extractToRight<EDPL_MAX_COUNT_0_MAX_COUNT,
           EDPL_MAX_COUNT_0_MAX_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access EDPL_MAX_COUNT_0_MAX_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EDPL_MAX_COUNT_0_MAX_COUNT]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
