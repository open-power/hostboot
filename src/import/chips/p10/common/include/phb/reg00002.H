/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00002.H $          */
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

#ifndef __PHB_REG00002_H_
#define __PHB_REG00002_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> PREP_[PHB5_SCOM_UV_SEC_EXCL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHB5_SCOM_UV_SEC_EXCL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHB5_SCOM_UV_SEC_EXCL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PHB5_SCOM_UV_SEC_EXCL]

//>> GET_[PHB5_SCOM_UV_SEC_EXCL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHB5_SCOM_UV_SEC_EXCL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHB5_SCOM_UV_SEC_EXCL;
#endif
    return fapi2::getScom(i_target, PHB5_SCOM_UV_SEC_EXCL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_EXCL]

//>> PUT_[PHB5_SCOM_UV_SEC_EXCL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHB5_SCOM_UV_SEC_EXCL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return fapi2::putScom(i_target, PHB5_SCOM_UV_SEC_EXCL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PHB5_SCOM_UV_SEC_EXCL]


//>> SET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_EXCL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]

//>> SET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_EXCL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_EXCL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]

//>> SET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.setBit<PHB5_SCOM_UV_SEC_EXCL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]

//>> CLEAR_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.clearBit<PHB5_SCOM_UV_SEC_EXCL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]

//>> GET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return i_data.extractToRight<PHB5_SCOM_UV_SEC_EXCL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]

//>> GET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]
static inline bool GET_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return i_data.getBit<PHB5_SCOM_UV_SEC_EXCL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_EXCL_ENABLE]

//>> SET_[PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE,
           PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE]

//>> SET_[PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE,
           PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE]

//>> GET_[PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE]
static inline fapi2::buffer<uint64_t>& GET_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return i_data.extractToRight<PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE,
           PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE]

//>> SET_[PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE,
           PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE]

//>> SET_[PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE,
           PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE]

//>> GET_[PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE]
static inline fapi2::buffer<uint64_t>& GET_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_EXCL));
#endif
    return i_data.extractToRight<PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE,
           PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE]

//>> PREP_[REGS_CERR_RPT0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_CERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CERR_RPT0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_CERR_RPT0_REG]

//>> GET_[REGS_CERR_RPT0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_CERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CERR_RPT0_REG;
#endif
    return fapi2::getScom(i_target, REGS_CERR_RPT0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_CERR_RPT0_REG]

//>> PUT_[REGS_CERR_RPT0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_CERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT0_REG));
#endif
    return fapi2::putScom(i_target, REGS_CERR_RPT0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_CERR_RPT0_REG]


//>> SET_[REGS_CERR_RPT0_REG_CERR_RPT0]
static inline fapi2::buffer<uint64_t>& SET_REGS_CERR_RPT0_REG_CERR_RPT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT0_REG));
#endif
    return o_data.insertFromRight<REGS_CERR_RPT0_REG_CERR_RPT0,
           REGS_CERR_RPT0_REG_CERR_RPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_CERR_RPT0_REG_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CERR_RPT0_REG_CERR_RPT0]

//>> SET_[REGS_CERR_RPT0_REG_CERR_RPT0]
static inline fapi2::buffer<uint64_t>& SET_REGS_CERR_RPT0_REG_CERR_RPT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT0_REG));
#endif
    return o_data.insertFromRight<REGS_CERR_RPT0_REG_CERR_RPT0,
           REGS_CERR_RPT0_REG_CERR_RPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_CERR_RPT0_REG_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CERR_RPT0_REG_CERR_RPT0]

//>> GET_[REGS_CERR_RPT0_REG_CERR_RPT0]
static inline fapi2::buffer<uint64_t>& GET_REGS_CERR_RPT0_REG_CERR_RPT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT0_REG));
#endif
    return i_data.extractToRight<REGS_CERR_RPT0_REG_CERR_RPT0,
           REGS_CERR_RPT0_REG_CERR_RPT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_CERR_RPT0_REG_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_CERR_RPT0_REG_CERR_RPT0]

//>> PREP_[REGS_CERR_RPT1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_CERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CERR_RPT1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_CERR_RPT1_REG]

//>> GET_[REGS_CERR_RPT1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_CERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CERR_RPT1_REG;
#endif
    return fapi2::getScom(i_target, REGS_CERR_RPT1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_CERR_RPT1_REG]

//>> PUT_[REGS_CERR_RPT1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_CERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT1_REG));
#endif
    return fapi2::putScom(i_target, REGS_CERR_RPT1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_CERR_RPT1_REG]


//>> SET_[REGS_CERR_RPT1_REG_CERR_RPT1]
static inline fapi2::buffer<uint64_t>& SET_REGS_CERR_RPT1_REG_CERR_RPT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT1_REG));
#endif
    return o_data.insertFromRight<REGS_CERR_RPT1_REG_CERR_RPT1,
           REGS_CERR_RPT1_REG_CERR_RPT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_CERR_RPT1_REG_CERR_RPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CERR_RPT1_REG_CERR_RPT1]

//>> SET_[REGS_CERR_RPT1_REG_CERR_RPT1]
static inline fapi2::buffer<uint64_t>& SET_REGS_CERR_RPT1_REG_CERR_RPT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT1_REG));
#endif
    return o_data.insertFromRight<REGS_CERR_RPT1_REG_CERR_RPT1,
           REGS_CERR_RPT1_REG_CERR_RPT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_CERR_RPT1_REG_CERR_RPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CERR_RPT1_REG_CERR_RPT1]

//>> GET_[REGS_CERR_RPT1_REG_CERR_RPT1]
static inline fapi2::buffer<uint64_t>& GET_REGS_CERR_RPT1_REG_CERR_RPT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT1_REG));
#endif
    return i_data.extractToRight<REGS_CERR_RPT1_REG_CERR_RPT1,
           REGS_CERR_RPT1_REG_CERR_RPT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_CERR_RPT1_REG_CERR_RPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_CERR_RPT1_REG_CERR_RPT1]

//>> PREP_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL;
#endif
    return fapi2::getScom(i_target, RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL]

//>> PUT_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return fapi2::putScom(i_target, RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL]


//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]

//>> SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]

//>> CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]

//>> GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]
static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
