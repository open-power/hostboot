/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00009.H $          */
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

#ifndef __PAU_REG00009_H_
#define __PAU_REG00009_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[CS_SM1_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM1_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_GENID_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM1_SNP_MISC_GENID_BAR]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM1_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_GENID_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM1_SNP_MISC_GENID_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR]

//>> PUT_[CS_SM1_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM1_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM1_SNP_MISC_GENID_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM1_SNP_MISC_GENID_BAR]


//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> CLEAR_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline bool GET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> CLEAR_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline bool GET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> CLEAR_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline bool GET_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> CLEAR_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline bool GET_CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> PREP_[MISC_FENCE_STATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MISC_FENCE_STATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MISC_FENCE_STATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MISC_FENCE_STATE]

//>> GET_[MISC_FENCE_STATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MISC_FENCE_STATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MISC_FENCE_STATE;
#endif
    return fapi2::getScom(i_target, MISC_FENCE_STATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MISC_FENCE_STATE]

//>> PUT_[MISC_FENCE_STATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MISC_FENCE_STATE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return fapi2::putScom(i_target, MISC_FENCE_STATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MISC_FENCE_STATE]


//>> SET_[MISC_FENCE_STATE_0]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_FENCE_STATE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_0]

//>> SET_[MISC_FENCE_STATE_0]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_FENCE_STATE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_0]

//>> SET_[MISC_FENCE_STATE_0]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.setBit<MISC_FENCE_STATE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_FENCE_STATE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_0]

//>> CLEAR_[MISC_FENCE_STATE_0]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_FENCE_STATE_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.clearBit<MISC_FENCE_STATE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_FENCE_STATE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_FENCE_STATE_0]

//>> GET_[MISC_FENCE_STATE_0]
static inline fapi2::buffer<uint64_t>& GET_MISC_FENCE_STATE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.extractToRight<MISC_FENCE_STATE_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_FENCE_STATE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_0]

//>> GET_[MISC_FENCE_STATE_0]
static inline bool GET_MISC_FENCE_STATE_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.getBit<MISC_FENCE_STATE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_FENCE_STATE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_0]

//>> SET_[MISC_FENCE_STATE_1]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_FENCE_STATE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_1]

//>> SET_[MISC_FENCE_STATE_1]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_FENCE_STATE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_1]

//>> SET_[MISC_FENCE_STATE_1]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.setBit<MISC_FENCE_STATE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_FENCE_STATE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_1]

//>> CLEAR_[MISC_FENCE_STATE_1]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_FENCE_STATE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.clearBit<MISC_FENCE_STATE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_FENCE_STATE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_FENCE_STATE_1]

//>> GET_[MISC_FENCE_STATE_1]
static inline fapi2::buffer<uint64_t>& GET_MISC_FENCE_STATE_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.extractToRight<MISC_FENCE_STATE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_FENCE_STATE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_1]

//>> GET_[MISC_FENCE_STATE_1]
static inline bool GET_MISC_FENCE_STATE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.getBit<MISC_FENCE_STATE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_FENCE_STATE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_1]

//>> SET_[MISC_FENCE_STATE_2]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_FENCE_STATE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_2]

//>> SET_[MISC_FENCE_STATE_2]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_FENCE_STATE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_2]

//>> SET_[MISC_FENCE_STATE_2]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.setBit<MISC_FENCE_STATE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_FENCE_STATE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_2]

//>> CLEAR_[MISC_FENCE_STATE_2]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_FENCE_STATE_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.clearBit<MISC_FENCE_STATE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_FENCE_STATE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_FENCE_STATE_2]

//>> GET_[MISC_FENCE_STATE_2]
static inline fapi2::buffer<uint64_t>& GET_MISC_FENCE_STATE_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.extractToRight<MISC_FENCE_STATE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_FENCE_STATE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_2]

//>> GET_[MISC_FENCE_STATE_2]
static inline bool GET_MISC_FENCE_STATE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.getBit<MISC_FENCE_STATE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_FENCE_STATE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_2]

//>> SET_[MISC_FENCE_STATE_3]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_FENCE_STATE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_3]

//>> SET_[MISC_FENCE_STATE_3]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_FENCE_STATE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_3]

//>> SET_[MISC_FENCE_STATE_3]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.setBit<MISC_FENCE_STATE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_FENCE_STATE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_3]

//>> CLEAR_[MISC_FENCE_STATE_3]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_FENCE_STATE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.clearBit<MISC_FENCE_STATE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_FENCE_STATE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_FENCE_STATE_3]

//>> GET_[MISC_FENCE_STATE_3]
static inline fapi2::buffer<uint64_t>& GET_MISC_FENCE_STATE_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.extractToRight<MISC_FENCE_STATE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_FENCE_STATE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_3]

//>> GET_[MISC_FENCE_STATE_3]
static inline bool GET_MISC_FENCE_STATE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.getBit<MISC_FENCE_STATE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_FENCE_STATE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_3]

//>> SET_[MISC_FENCE_STATE_4]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_FENCE_STATE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_4]

//>> SET_[MISC_FENCE_STATE_4]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.insertFromRight<MISC_FENCE_STATE_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_FENCE_STATE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_4]

//>> SET_[MISC_FENCE_STATE_4]
static inline fapi2::buffer<uint64_t>& SET_MISC_FENCE_STATE_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.setBit<MISC_FENCE_STATE_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_FENCE_STATE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_FENCE_STATE_4]

//>> CLEAR_[MISC_FENCE_STATE_4]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_FENCE_STATE_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return o_data.clearBit<MISC_FENCE_STATE_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_FENCE_STATE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_FENCE_STATE_4]

//>> GET_[MISC_FENCE_STATE_4]
static inline fapi2::buffer<uint64_t>& GET_MISC_FENCE_STATE_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.extractToRight<MISC_FENCE_STATE_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_FENCE_STATE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_4]

//>> GET_[MISC_FENCE_STATE_4]
static inline bool GET_MISC_FENCE_STATE_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_FENCE_STATE));
#endif
    return i_data.getBit<MISC_FENCE_STATE_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_FENCE_STATE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_FENCE_STATE_4]

//>> PREP_[CS_CTL_MISC_CONFIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_CTL_MISC_CONFIG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_CONFIG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_CTL_MISC_CONFIG2]

//>> GET_[CS_CTL_MISC_CONFIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_CTL_MISC_CONFIG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_CONFIG2;
#endif
    return fapi2::getScom(i_target, CS_CTL_MISC_CONFIG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2]

//>> PUT_[CS_CTL_MISC_CONFIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_CTL_MISC_CONFIG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return fapi2::putScom(i_target, CS_CTL_MISC_CONFIG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_CTL_MISC_CONFIG2]


//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]
static inline bool GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]
static inline bool GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]
static inline bool GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]
static inline bool GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]

//>> SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]

//>> GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]
static inline bool GET_CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE,
           CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE,
           CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE]

//>> GET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE,
           CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]

//>> GET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]

//>> GET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]
static inline bool GET_CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]

//>> GET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]
static inline bool GET_CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]

//>> SET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]

//>> CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]

//>> GET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]
static inline bool GET_CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK]

//>> SET_[CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_2_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_2_RESERVED1,
           CS_CTL_MISC_CONFIG2_2_RESERVED1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> SET_[CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_2_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_2_RESERVED1,
           CS_CTL_MISC_CONFIG2_2_RESERVED1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> GET_[CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_2_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_2_RESERVED1,
           CS_CTL_MISC_CONFIG2_2_RESERVED1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]

//>> CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]
static inline bool GET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]

//>> CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]
static inline bool GET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]

//>> CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]
static inline bool GET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]

//>> CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]
static inline bool GET_P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]

//>> CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]
static inline bool GET_P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> SET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.setBit<P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.clearBit<P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> GET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]
static inline bool GET_P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.getBit<P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_RATE_INC]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_RATE_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_GENID_RATE_INC,
           CS_CTL_MISC_CONFIG2_GENID_RATE_INC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_RATE_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_RATE_INC]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_RATE_INC]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_RATE_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_GENID_RATE_INC,
           CS_CTL_MISC_CONFIG2_GENID_RATE_INC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_RATE_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_RATE_INC]

//>> GET_[CS_CTL_MISC_CONFIG2_GENID_RATE_INC]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_GENID_RATE_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_GENID_RATE_INC,
           CS_CTL_MISC_CONFIG2_GENID_RATE_INC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_RATE_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_GENID_RATE_INC]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_RATE_DEC]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_RATE_DEC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_GENID_RATE_DEC,
           CS_CTL_MISC_CONFIG2_GENID_RATE_DEC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_RATE_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_RATE_DEC]

//>> SET_[CS_CTL_MISC_CONFIG2_GENID_RATE_DEC]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_CONFIG2_GENID_RATE_DEC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_CONFIG2_GENID_RATE_DEC,
           CS_CTL_MISC_CONFIG2_GENID_RATE_DEC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_RATE_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_CONFIG2_GENID_RATE_DEC]

//>> GET_[CS_CTL_MISC_CONFIG2_GENID_RATE_DEC]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_CONFIG2_GENID_RATE_DEC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_CONFIG2));
#endif
    return i_data.extractToRight<CS_CTL_MISC_CONFIG2_GENID_RATE_DEC,
           CS_CTL_MISC_CONFIG2_GENID_RATE_DEC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_CONFIG2_GENID_RATE_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_CONFIG2_GENID_RATE_DEC]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
