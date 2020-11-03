/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00004.H $          */
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

#ifndef __PAU_REG00004_H_
#define __PAU_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[CS_CTL_MISC_FENCE_CONTROL1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_CTL_MISC_FENCE_CONTROL1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_FENCE_CONTROL1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_CTL_MISC_FENCE_CONTROL1]

//>> GET_[CS_CTL_MISC_FENCE_CONTROL1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_CTL_MISC_FENCE_CONTROL1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_FENCE_CONTROL1;
#endif
    return fapi2::getScom(i_target, CS_CTL_MISC_FENCE_CONTROL1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_CTL_MISC_FENCE_CONTROL1]

//>> PUT_[CS_CTL_MISC_FENCE_CONTROL1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_CTL_MISC_FENCE_CONTROL1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_FENCE_CONTROL1));
#endif
    return fapi2::putScom(i_target, CS_CTL_MISC_FENCE_CONTROL1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_CTL_MISC_FENCE_CONTROL1]


//>> SET_[CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_FENCE_CONTROL1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE,
           CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE]

//>> SET_[CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_FENCE_CONTROL1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE,
           CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE]

//>> GET_[CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_FENCE_CONTROL1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE,
           CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_FENCE_CONTROL1_1_REQUEST_FENCE]

//>> SET_[CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_FENCE_CONTROL1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED,
           CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED]

//>> SET_[CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_FENCE_CONTROL1));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED,
           CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED]

//>> GET_[CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_FENCE_CONTROL1));
#endif
    return i_data.extractToRight<CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED,
           CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_FENCE_CONTROL1_CONTROL1_RESERVED]

//>> PREP_[CS_SM1_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM1_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_NDT0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM1_SNP_MISC_NDT0_BAR]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM1_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_NDT0_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM1_SNP_MISC_NDT0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR]

//>> PUT_[CS_SM1_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM1_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM1_SNP_MISC_NDT0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM1_SNP_MISC_NDT0_BAR]


//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> CLEAR_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline bool GET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> CLEAR_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline bool GET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> CLEAR_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline bool GET_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> CLEAR_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline bool GET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> PREP_[CS_SM1_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM1_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_NDT1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM1_SNP_MISC_NDT1_BAR]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM1_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_NDT1_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM1_SNP_MISC_NDT1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR]

//>> PUT_[CS_SM1_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM1_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM1_SNP_MISC_NDT1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM1_SNP_MISC_NDT1_BAR]


//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> CLEAR_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline bool GET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> CLEAR_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline bool GET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> CLEAR_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline bool GET_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> CLEAR_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline bool GET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>> SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>> GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>> PREP_[CS_SM3_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM3_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM3_SNP_MISC_GENID_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM3_SNP_MISC_GENID_BAR]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM3_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM3_SNP_MISC_GENID_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM3_SNP_MISC_GENID_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR]

//>> PUT_[CS_SM3_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM3_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM3_SNP_MISC_GENID_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM3_SNP_MISC_GENID_BAR]


//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> CLEAR_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline bool GET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> CLEAR_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline bool GET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> CLEAR_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline bool GET_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> CLEAR_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline bool GET_CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
