/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00010.H $          */
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

#ifndef __PAU_REG00010_H_
#define __PAU_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[XTS_REG_PMU_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_REG_PMU_CNT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_PMU_CNT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XTS_REG_PMU_CNT]

//>> GET_[XTS_REG_PMU_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_REG_PMU_CNT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_PMU_CNT;
#endif
    return fapi2::getScom(i_target, XTS_REG_PMU_CNT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XTS_REG_PMU_CNT]

//>> PUT_[XTS_REG_PMU_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_REG_PMU_CNT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return fapi2::putScom(i_target, XTS_REG_PMU_CNT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XTS_REG_PMU_CNT]


//>> SET_[XTS_REG_PMU_CNT_0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_PMU_CNT_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return o_data.insertFromRight<XTS_REG_PMU_CNT_0,
           XTS_REG_PMU_CNT_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_PMU_CNT_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_PMU_CNT_0]

//>> SET_[XTS_REG_PMU_CNT_0]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_PMU_CNT_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return o_data.insertFromRight<XTS_REG_PMU_CNT_0,
           XTS_REG_PMU_CNT_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_PMU_CNT_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_PMU_CNT_0]

//>> GET_[XTS_REG_PMU_CNT_0]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_PMU_CNT_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return i_data.extractToRight<XTS_REG_PMU_CNT_0,
           XTS_REG_PMU_CNT_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_PMU_CNT_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_PMU_CNT_0]

//>> SET_[XTS_REG_PMU_CNT_1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_PMU_CNT_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return o_data.insertFromRight<XTS_REG_PMU_CNT_1,
           XTS_REG_PMU_CNT_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_PMU_CNT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_PMU_CNT_1]

//>> SET_[XTS_REG_PMU_CNT_1]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_PMU_CNT_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return o_data.insertFromRight<XTS_REG_PMU_CNT_1,
           XTS_REG_PMU_CNT_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_PMU_CNT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_PMU_CNT_1]

//>> GET_[XTS_REG_PMU_CNT_1]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_PMU_CNT_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return i_data.extractToRight<XTS_REG_PMU_CNT_1,
           XTS_REG_PMU_CNT_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_PMU_CNT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_PMU_CNT_1]

//>> SET_[XTS_REG_PMU_CNT_2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_PMU_CNT_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return o_data.insertFromRight<XTS_REG_PMU_CNT_2,
           XTS_REG_PMU_CNT_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_PMU_CNT_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_PMU_CNT_2]

//>> SET_[XTS_REG_PMU_CNT_2]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_PMU_CNT_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return o_data.insertFromRight<XTS_REG_PMU_CNT_2,
           XTS_REG_PMU_CNT_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_PMU_CNT_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_PMU_CNT_2]

//>> GET_[XTS_REG_PMU_CNT_2]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_PMU_CNT_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return i_data.extractToRight<XTS_REG_PMU_CNT_2,
           XTS_REG_PMU_CNT_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_PMU_CNT_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_PMU_CNT_2]

//>> SET_[XTS_REG_PMU_CNT_3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_PMU_CNT_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return o_data.insertFromRight<XTS_REG_PMU_CNT_3,
           XTS_REG_PMU_CNT_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XTS_REG_PMU_CNT_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_PMU_CNT_3]

//>> SET_[XTS_REG_PMU_CNT_3]
static inline fapi2::buffer<uint64_t>& SET_XTS_REG_PMU_CNT_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return o_data.insertFromRight<XTS_REG_PMU_CNT_3,
           XTS_REG_PMU_CNT_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XTS_REG_PMU_CNT_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XTS_REG_PMU_CNT_3]

//>> GET_[XTS_REG_PMU_CNT_3]
static inline fapi2::buffer<uint64_t>& GET_XTS_REG_PMU_CNT_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_PMU_CNT));
#endif
    return i_data.extractToRight<XTS_REG_PMU_CNT_3,
           XTS_REG_PMU_CNT_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XTS_REG_PMU_CNT_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XTS_REG_PMU_CNT_3]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
