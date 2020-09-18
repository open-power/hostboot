/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00006.H $          */
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

#ifndef __MCC_REG00006_H_
#define __MCC_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[CRYPTO_DECRYPT_CRYPTOCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTOCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CRYPTO_DECRYPT_CRYPTOCFG]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTOCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOCFG;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTOCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG]

//>> PUT_[CRYPTO_DECRYPT_CRYPTOCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTOCFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTOCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CRYPTO_DECRYPT_CRYPTOCFG]


//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11,
           CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11,
           CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11,
           CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ,
           CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.setBit<CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.clearBit<CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]
static inline bool GET_CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.getBit<CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31,
           CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31]

//>> SET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31,
           CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31]

//>> GET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOCFG));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31,
           CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
