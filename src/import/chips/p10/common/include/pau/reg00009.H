/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00009.H $          */
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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
