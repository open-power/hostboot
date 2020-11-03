/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00017.H $          */
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

#ifndef __PAU_REG00017_H_
#define __PAU_REG00017_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[CS_SM0_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM0_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM0_SNP_MISC_GENID_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM0_SNP_MISC_GENID_BAR]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM0_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM0_SNP_MISC_GENID_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM0_SNP_MISC_GENID_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR]

//>> PUT_[CS_SM0_SNP_MISC_GENID_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM0_SNP_MISC_GENID_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM0_SNP_MISC_GENID_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM0_SNP_MISC_GENID_BAR]


//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> CLEAR_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]
static inline bool GET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> CLEAR_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]
static inline bool GET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> CLEAR_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]
static inline bool GET_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED1]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR,
           CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2,
           CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_GENID_RESERVED2]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> CLEAR_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]
static inline bool GET_CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GENID_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON]

//>> PREP_[CS_SM2_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM2_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_GPU0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM2_SNP_MISC_GPU0_BAR]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM2_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_GPU0_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM2_SNP_MISC_GPU0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR]

//>> PUT_[CS_SM2_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM2_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM2_SNP_MISC_GPU0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM2_SNP_MISC_GPU0_BAR]


//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_MODE,
           CS_SM2_SNP_MISC_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_MODE,
           CS_SM2_SNP_MISC_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_MODE,
           CS_SM2_SNP_MISC_GPU0_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]

//>> SET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU0_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]

//>> GET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]
static inline bool GET_CS_SM2_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU0_BAR_RESERVED]

//>> PREP_[CS_SM2_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM2_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_GPU1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM2_SNP_MISC_GPU1_BAR]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM2_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM2_SNP_MISC_GPU1_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM2_SNP_MISC_GPU1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR]

//>> PUT_[CS_SM2_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM2_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM2_SNP_MISC_GPU1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM2_SNP_MISC_GPU1_BAR]


//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_MODE,
           CS_SM2_SNP_MISC_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_MODE,
           CS_SM2_SNP_MISC_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_MODE,
           CS_SM2_SNP_MISC_GPU1_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM2_SNP_MISC_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]

//>> SET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM2_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM2_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]

//>> CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM2_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM2_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_SM2_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM2_SNP_MISC_GPU1_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]

//>> GET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]
static inline bool GET_CS_SM2_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM2_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM2_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM2_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM2_SNP_MISC_GPU1_BAR_RESERVED]

//>> PREP_[MISC_REGS_INT_REQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MISC_REGS_INT_REQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MISC_REGS_INT_REQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MISC_REGS_INT_REQ]

//>> GET_[MISC_REGS_INT_REQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MISC_REGS_INT_REQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MISC_REGS_INT_REQ;
#endif
    return fapi2::getScom(i_target, MISC_REGS_INT_REQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MISC_REGS_INT_REQ]

//>> PUT_[MISC_REGS_INT_REQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MISC_REGS_INT_REQ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return fapi2::putScom(i_target, MISC_REGS_INT_REQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MISC_REGS_INT_REQ]


//>> SET_[MISC_REGS_INT_REQ_00]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_00]

//>> SET_[MISC_REGS_INT_REQ_00]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_00]

//>> SET_[MISC_REGS_INT_REQ_00]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_00]

//>> CLEAR_[MISC_REGS_INT_REQ_00]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_00]

//>> GET_[MISC_REGS_INT_REQ_00]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_00]

//>> GET_[MISC_REGS_INT_REQ_00]
static inline bool GET_MISC_REGS_INT_REQ_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_00]

//>> SET_[MISC_REGS_INT_REQ_01]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_01]

//>> SET_[MISC_REGS_INT_REQ_01]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_01]

//>> SET_[MISC_REGS_INT_REQ_01]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_01]

//>> CLEAR_[MISC_REGS_INT_REQ_01]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_01]

//>> GET_[MISC_REGS_INT_REQ_01]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_01]

//>> GET_[MISC_REGS_INT_REQ_01]
static inline bool GET_MISC_REGS_INT_REQ_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_01]

//>> SET_[MISC_REGS_INT_REQ_02]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_02]

//>> SET_[MISC_REGS_INT_REQ_02]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_02]

//>> SET_[MISC_REGS_INT_REQ_02]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_02]

//>> CLEAR_[MISC_REGS_INT_REQ_02]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_02]

//>> GET_[MISC_REGS_INT_REQ_02]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_02]

//>> GET_[MISC_REGS_INT_REQ_02]
static inline bool GET_MISC_REGS_INT_REQ_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_02]

//>> SET_[MISC_REGS_INT_REQ_03]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_03]

//>> SET_[MISC_REGS_INT_REQ_03]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_03]

//>> SET_[MISC_REGS_INT_REQ_03]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_03]

//>> CLEAR_[MISC_REGS_INT_REQ_03]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_03]

//>> GET_[MISC_REGS_INT_REQ_03]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_03]

//>> GET_[MISC_REGS_INT_REQ_03]
static inline bool GET_MISC_REGS_INT_REQ_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_03]

//>> SET_[MISC_REGS_INT_REQ_12]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_12]

//>> SET_[MISC_REGS_INT_REQ_12]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_12]

//>> SET_[MISC_REGS_INT_REQ_12]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_12]

//>> CLEAR_[MISC_REGS_INT_REQ_12]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_12]

//>> GET_[MISC_REGS_INT_REQ_12]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_12]

//>> GET_[MISC_REGS_INT_REQ_12]
static inline bool GET_MISC_REGS_INT_REQ_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_12]

//>> SET_[MISC_REGS_INT_REQ_13]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_13]

//>> SET_[MISC_REGS_INT_REQ_13]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_13]

//>> SET_[MISC_REGS_INT_REQ_13]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_13]

//>> CLEAR_[MISC_REGS_INT_REQ_13]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_13]

//>> GET_[MISC_REGS_INT_REQ_13]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_13]

//>> GET_[MISC_REGS_INT_REQ_13]
static inline bool GET_MISC_REGS_INT_REQ_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_13]

//>> SET_[MISC_REGS_INT_REQ_18]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_18]

//>> SET_[MISC_REGS_INT_REQ_18]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_18]

//>> SET_[MISC_REGS_INT_REQ_18]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_18]

//>> CLEAR_[MISC_REGS_INT_REQ_18]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_18]

//>> GET_[MISC_REGS_INT_REQ_18]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_18]

//>> GET_[MISC_REGS_INT_REQ_18]
static inline bool GET_MISC_REGS_INT_REQ_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_18]

//>> SET_[MISC_REGS_INT_REQ_19]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_19]

//>> SET_[MISC_REGS_INT_REQ_19]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_19]

//>> SET_[MISC_REGS_INT_REQ_19]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_19]

//>> CLEAR_[MISC_REGS_INT_REQ_19]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_19]

//>> GET_[MISC_REGS_INT_REQ_19]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_19]

//>> GET_[MISC_REGS_INT_REQ_19]
static inline bool GET_MISC_REGS_INT_REQ_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_19]

//>> SET_[MISC_REGS_INT_REQ_20]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_20]

//>> SET_[MISC_REGS_INT_REQ_20]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_20]

//>> SET_[MISC_REGS_INT_REQ_20]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_20]

//>> CLEAR_[MISC_REGS_INT_REQ_20]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_20]

//>> GET_[MISC_REGS_INT_REQ_20]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_20]

//>> GET_[MISC_REGS_INT_REQ_20]
static inline bool GET_MISC_REGS_INT_REQ_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_20]

//>> SET_[MISC_REGS_INT_REQ_21]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_21]

//>> SET_[MISC_REGS_INT_REQ_21]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_21]

//>> SET_[MISC_REGS_INT_REQ_21]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_21]

//>> CLEAR_[MISC_REGS_INT_REQ_21]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_21]

//>> GET_[MISC_REGS_INT_REQ_21]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_21]

//>> GET_[MISC_REGS_INT_REQ_21]
static inline bool GET_MISC_REGS_INT_REQ_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_21]

//>> SET_[MISC_REGS_INT_REQ_23]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_23]

//>> SET_[MISC_REGS_INT_REQ_23]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_23]

//>> SET_[MISC_REGS_INT_REQ_23]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_23]

//>> CLEAR_[MISC_REGS_INT_REQ_23]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_23]

//>> GET_[MISC_REGS_INT_REQ_23]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_23]

//>> GET_[MISC_REGS_INT_REQ_23]
static inline bool GET_MISC_REGS_INT_REQ_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_23]

//>> SET_[MISC_REGS_INT_REQ_24]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_24]

//>> SET_[MISC_REGS_INT_REQ_24]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_24]

//>> SET_[MISC_REGS_INT_REQ_24]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_24]

//>> CLEAR_[MISC_REGS_INT_REQ_24]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_24]

//>> GET_[MISC_REGS_INT_REQ_24]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_24]

//>> GET_[MISC_REGS_INT_REQ_24]
static inline bool GET_MISC_REGS_INT_REQ_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_24]

//>> SET_[MISC_REGS_INT_REQ_35]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_35]

//>> SET_[MISC_REGS_INT_REQ_35]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_35]

//>> SET_[MISC_REGS_INT_REQ_35]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_35]

//>> CLEAR_[MISC_REGS_INT_REQ_35]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_35]

//>> GET_[MISC_REGS_INT_REQ_35]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_35]

//>> GET_[MISC_REGS_INT_REQ_35]
static inline bool GET_MISC_REGS_INT_REQ_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_35]

//>> SET_[MISC_REGS_INT_REQ_36]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_36]

//>> SET_[MISC_REGS_INT_REQ_36]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_36]

//>> SET_[MISC_REGS_INT_REQ_36]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_36]

//>> CLEAR_[MISC_REGS_INT_REQ_36]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_36]

//>> GET_[MISC_REGS_INT_REQ_36]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_36]

//>> GET_[MISC_REGS_INT_REQ_36]
static inline bool GET_MISC_REGS_INT_REQ_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_36]

//>> SET_[MISC_REGS_INT_REQ_37]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_37]

//>> SET_[MISC_REGS_INT_REQ_37]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_37]

//>> SET_[MISC_REGS_INT_REQ_37]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_37]

//>> CLEAR_[MISC_REGS_INT_REQ_37]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_37]

//>> GET_[MISC_REGS_INT_REQ_37]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_37]

//>> GET_[MISC_REGS_INT_REQ_37]
static inline bool GET_MISC_REGS_INT_REQ_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_37]

//>> SET_[MISC_REGS_INT_REQ_38]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_38]

//>> SET_[MISC_REGS_INT_REQ_38]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_38]

//>> SET_[MISC_REGS_INT_REQ_38]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_38]

//>> CLEAR_[MISC_REGS_INT_REQ_38]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_38]

//>> GET_[MISC_REGS_INT_REQ_38]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_38]

//>> GET_[MISC_REGS_INT_REQ_38]
static inline bool GET_MISC_REGS_INT_REQ_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_38]

//>> SET_[MISC_REGS_INT_REQ_39]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_39]

//>> SET_[MISC_REGS_INT_REQ_39]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_39]

//>> SET_[MISC_REGS_INT_REQ_39]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_39]

//>> CLEAR_[MISC_REGS_INT_REQ_39]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_39]

//>> GET_[MISC_REGS_INT_REQ_39]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_39]

//>> GET_[MISC_REGS_INT_REQ_39]
static inline bool GET_MISC_REGS_INT_REQ_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_39]

//>> SET_[MISC_REGS_INT_REQ_40]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access MISC_REGS_INT_REQ_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_40]

//>> SET_[MISC_REGS_INT_REQ_40]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.insertFromRight<MISC_REGS_INT_REQ_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access MISC_REGS_INT_REQ_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_40]

//>> SET_[MISC_REGS_INT_REQ_40]
static inline fapi2::buffer<uint64_t>& SET_MISC_REGS_INT_REQ_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.setBit<MISC_REGS_INT_REQ_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access MISC_REGS_INT_REQ_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MISC_REGS_INT_REQ_40]

//>> CLEAR_[MISC_REGS_INT_REQ_40]
static inline fapi2::buffer<uint64_t>& CLEAR_MISC_REGS_INT_REQ_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return o_data.clearBit<MISC_REGS_INT_REQ_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access MISC_REGS_INT_REQ_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MISC_REGS_INT_REQ_40]

//>> GET_[MISC_REGS_INT_REQ_40]
static inline fapi2::buffer<uint64_t>& GET_MISC_REGS_INT_REQ_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.extractToRight<MISC_REGS_INT_REQ_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access MISC_REGS_INT_REQ_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_40]

//>> GET_[MISC_REGS_INT_REQ_40]
static inline bool GET_MISC_REGS_INT_REQ_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MISC_REGS_INT_REQ));
#endif
    return i_data.getBit<MISC_REGS_INT_REQ_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access MISC_REGS_INT_REQ_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MISC_REGS_INT_REQ_40]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
