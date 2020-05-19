/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00018.H $          */
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

#ifndef __PAU_REG00018_H_
#define __PAU_REG00018_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[CS_SM0_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM0_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM0_SNP_MISC_GPU0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM0_SNP_MISC_GPU0_BAR]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM0_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM0_SNP_MISC_GPU0_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM0_SNP_MISC_GPU0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR]

//>> PUT_[CS_SM0_SNP_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM0_SNP_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM0_SNP_MISC_GPU0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM0_SNP_MISC_GPU0_BAR]


//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK,
           CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_ADDR_MASK]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT,
           CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_4T_SELECT]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_MODE,
           CS_SM0_SNP_MISC_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_MODE,
           CS_SM0_SNP_MISC_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_MODE,
           CS_SM0_SNP_MISC_GPU0_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_POISON]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]

//>> SET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU0_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]

//>> GET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]
static inline bool GET_CS_SM0_SNP_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU0_BAR_RESERVED]

//>> PREP_[CS_SM0_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM0_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM0_SNP_MISC_GPU1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM0_SNP_MISC_GPU1_BAR]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM0_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM0_SNP_MISC_GPU1_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM0_SNP_MISC_GPU1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR]

//>> PUT_[CS_SM0_SNP_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM0_SNP_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM0_SNP_MISC_GPU1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM0_SNP_MISC_GPU1_BAR]


//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK,
           CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_ADDR_MASK]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT,
           CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_4T_SELECT]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_MODE,
           CS_SM0_SNP_MISC_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_MODE,
           CS_SM0_SNP_MISC_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_MODE,
           CS_SM0_SNP_MISC_GPU1_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_POISON]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_SM0_SNP_MISC_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]

//>> SET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_SM0_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_SM0_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]

//>> CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM0_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_SM0_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_SM0_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_SM0_SNP_MISC_GPU1_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]

//>> GET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]
static inline bool GET_CS_SM0_SNP_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM0_SNP_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_SM0_SNP_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM0_SNP_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM0_SNP_MISC_GPU1_BAR_RESERVED]

//>> PREP_[FIR_REG_0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_REG_0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR_REG_0_RW]

//>> GET_[FIR_REG_0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_REG_0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_0_RW;
#endif
    return fapi2::getScom(i_target, FIR_REG_0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR_REG_0_RW]

//>> PUT_[FIR_REG_0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_REG_0_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR_REG_0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR_REG_0_RW]

//>> PREP_[FIR_REG_0_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_REG_0_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_0_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR_REG_0_WO_AND]

//>> GET_[FIR_REG_0_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_REG_0_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_0_WO_AND;
#endif
    return fapi2::getScom(i_target, FIR_REG_0_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR_REG_0_WO_AND]

//>> PUT_[FIR_REG_0_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_REG_0_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR_REG_0_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR_REG_0_WO_AND]

//>> PREP_[FIR_REG_0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR_REG_0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FIR_REG_0_WO_OR]

//>> GET_[FIR_REG_0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR_REG_0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR_REG_0_WO_OR;
#endif
    return fapi2::getScom(i_target, FIR_REG_0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FIR_REG_0_WO_OR]

//>> PUT_[FIR_REG_0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR_REG_0_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return fapi2::putScom(i_target, FIR_REG_0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FIR_REG_0_WO_OR]


//>> SET_[FIR_REG_0_NTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_ARRAY_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_CE]

//>> SET_[FIR_REG_0_NTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_ARRAY_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_CE]

//>> SET_[FIR_REG_0_NTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_ARRAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_CE]

//>> CLEAR_[FIR_REG_0_NTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_ARRAY_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_ARRAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_ARRAY_CE]

//>> GET_[FIR_REG_0_NTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_ARRAY_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_ARRAY_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_ARRAY_CE]

//>> GET_[FIR_REG_0_NTL_ARRAY_CE]
static inline bool GET_FIR_REG_0_NTL_ARRAY_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_ARRAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_ARRAY_CE]

//>> SET_[FIR_REG_0_NTL_ARRAY_HDR_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_HDR_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_ARRAY_HDR_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_HDR_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_HDR_UE]

//>> SET_[FIR_REG_0_NTL_ARRAY_HDR_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_HDR_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_ARRAY_HDR_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_HDR_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_HDR_UE]

//>> SET_[FIR_REG_0_NTL_ARRAY_HDR_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_HDR_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_ARRAY_HDR_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_HDR_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_HDR_UE]

//>> CLEAR_[FIR_REG_0_NTL_ARRAY_HDR_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_ARRAY_HDR_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_ARRAY_HDR_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_HDR_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_ARRAY_HDR_UE]

//>> GET_[FIR_REG_0_NTL_ARRAY_HDR_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_ARRAY_HDR_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_ARRAY_HDR_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_HDR_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_ARRAY_HDR_UE]

//>> GET_[FIR_REG_0_NTL_ARRAY_HDR_UE]
static inline bool GET_FIR_REG_0_NTL_ARRAY_HDR_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_ARRAY_HDR_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_HDR_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_ARRAY_HDR_UE]

//>> SET_[FIR_REG_0_NTL_ARRAY_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_ARRAY_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_DATA_UE]

//>> SET_[FIR_REG_0_NTL_ARRAY_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_ARRAY_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_DATA_UE]

//>> SET_[FIR_REG_0_NTL_ARRAY_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_ARRAY_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_DATA_UE]

//>> CLEAR_[FIR_REG_0_NTL_ARRAY_DATA_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_ARRAY_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_ARRAY_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_ARRAY_DATA_UE]

//>> GET_[FIR_REG_0_NTL_ARRAY_DATA_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_ARRAY_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_ARRAY_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_ARRAY_DATA_UE]

//>> GET_[FIR_REG_0_NTL_ARRAY_DATA_UE]
static inline bool GET_FIR_REG_0_NTL_ARRAY_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_ARRAY_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_ARRAY_DATA_UE]

//>> SET_[FIR_REG_0_NTL_NVL_FLIT_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_FLIT_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_FLIT_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_FLIT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_FLIT_PERR]

//>> SET_[FIR_REG_0_NTL_NVL_FLIT_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_FLIT_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_FLIT_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_FLIT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_FLIT_PERR]

//>> SET_[FIR_REG_0_NTL_NVL_FLIT_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_FLIT_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_NVL_FLIT_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_FLIT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_FLIT_PERR]

//>> CLEAR_[FIR_REG_0_NTL_NVL_FLIT_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_NVL_FLIT_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_NVL_FLIT_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_FLIT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_NVL_FLIT_PERR]

//>> GET_[FIR_REG_0_NTL_NVL_FLIT_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_NVL_FLIT_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_NVL_FLIT_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_FLIT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_FLIT_PERR]

//>> GET_[FIR_REG_0_NTL_NVL_FLIT_PERR]
static inline bool GET_FIR_REG_0_NTL_NVL_FLIT_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_NVL_FLIT_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_FLIT_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_FLIT_PERR]

//>> SET_[FIR_REG_0_NTL_NVL_DATA_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_DATA_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_DATA_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_DATA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_DATA_PERR]

//>> SET_[FIR_REG_0_NTL_NVL_DATA_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_DATA_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_DATA_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_DATA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_DATA_PERR]

//>> SET_[FIR_REG_0_NTL_NVL_DATA_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_DATA_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_NVL_DATA_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_DATA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_DATA_PERR]

//>> CLEAR_[FIR_REG_0_NTL_NVL_DATA_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_NVL_DATA_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_NVL_DATA_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_DATA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_NVL_DATA_PERR]

//>> GET_[FIR_REG_0_NTL_NVL_DATA_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_NVL_DATA_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_NVL_DATA_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_DATA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_DATA_PERR]

//>> GET_[FIR_REG_0_NTL_NVL_DATA_PERR]
static inline bool GET_FIR_REG_0_NTL_NVL_DATA_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_NVL_DATA_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_DATA_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_DATA_PERR]

//>> SET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_PKT_MALFOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_PKT_MALFOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_MALFOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]

//>> SET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_PKT_MALFOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_PKT_MALFOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_MALFOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]

//>> SET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_PKT_MALFOR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_NVL_PKT_MALFOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_MALFOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]

//>> CLEAR_[FIR_REG_0_NTL_NVL_PKT_MALFOR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_NVL_PKT_MALFOR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_NVL_PKT_MALFOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_MALFOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_NVL_PKT_MALFOR]

//>> GET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_NVL_PKT_MALFOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_NVL_PKT_MALFOR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_MALFOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]

//>> GET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]
static inline bool GET_FIR_REG_0_NTL_NVL_PKT_MALFOR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_NVL_PKT_MALFOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_MALFOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_PKT_MALFOR]

//>> SET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]

//>> SET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]

//>> SET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]

//>> CLEAR_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]

//>> GET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]

//>> GET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]
static inline bool GET_FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_PKT_UNSUPPORTED]

//>> SET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_CONFIG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_CONFIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]

//>> SET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_CONFIG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_CONFIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]

//>> SET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_CONFIG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_NVL_CONFIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]

//>> CLEAR_[FIR_REG_0_NTL_NVL_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_NVL_CONFIG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_NVL_CONFIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_NVL_CONFIG_ERR]

//>> GET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_NVL_CONFIG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_NVL_CONFIG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]

//>> GET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]
static inline bool GET_FIR_REG_0_NTL_NVL_CONFIG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_NVL_CONFIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_CONFIG_ERR]

//>> SET_[FIR_REG_0_NTL_NVL_CRC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_CRC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_CRC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_CRC_ERR]

//>> SET_[FIR_REG_0_NTL_NVL_CRC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_CRC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_NVL_CRC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_CRC_ERR]

//>> SET_[FIR_REG_0_NTL_NVL_CRC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_NVL_CRC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_NVL_CRC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_NVL_CRC_ERR]

//>> CLEAR_[FIR_REG_0_NTL_NVL_CRC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_NVL_CRC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_NVL_CRC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_NVL_CRC_ERR]

//>> GET_[FIR_REG_0_NTL_NVL_CRC_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_NVL_CRC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_NVL_CRC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_CRC_ERR]

//>> GET_[FIR_REG_0_NTL_NVL_CRC_ERR]
static inline bool GET_FIR_REG_0_NTL_NVL_CRC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_NVL_CRC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_NVL_CRC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_NVL_CRC_ERR]

//>> SET_[FIR_REG_0_NTL_PRI_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_PRI_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_PRI_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_PRI_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_PRI_ERR]

//>> SET_[FIR_REG_0_NTL_PRI_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_PRI_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_PRI_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_PRI_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_PRI_ERR]

//>> SET_[FIR_REG_0_NTL_PRI_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_PRI_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_PRI_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_PRI_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_PRI_ERR]

//>> CLEAR_[FIR_REG_0_NTL_PRI_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_PRI_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_PRI_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_PRI_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_PRI_ERR]

//>> GET_[FIR_REG_0_NTL_PRI_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_PRI_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_PRI_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_PRI_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_PRI_ERR]

//>> GET_[FIR_REG_0_NTL_PRI_ERR]
static inline bool GET_FIR_REG_0_NTL_PRI_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_PRI_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_PRI_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_PRI_ERR]

//>> SET_[FIR_REG_0_NTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_LOGIC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_LOGIC_ERR]

//>> SET_[FIR_REG_0_NTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_LOGIC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_LOGIC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_LOGIC_ERR]

//>> SET_[FIR_REG_0_NTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_LOGIC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_LOGIC_ERR]

//>> CLEAR_[FIR_REG_0_NTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_LOGIC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_LOGIC_ERR]

//>> GET_[FIR_REG_0_NTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_LOGIC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_LOGIC_ERR]

//>> GET_[FIR_REG_0_NTL_LOGIC_ERR]
static inline bool GET_FIR_REG_0_NTL_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_LOGIC_ERR]

//>> SET_[FIR_REG_0_NTL_LMD_POISON]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_LMD_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_LMD_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_LMD_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_LMD_POISON]

//>> SET_[FIR_REG_0_NTL_LMD_POISON]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_LMD_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_LMD_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_LMD_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_LMD_POISON]

//>> SET_[FIR_REG_0_NTL_LMD_POISON]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_LMD_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_LMD_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_LMD_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_LMD_POISON]

//>> CLEAR_[FIR_REG_0_NTL_LMD_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_LMD_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_LMD_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_LMD_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_LMD_POISON]

//>> GET_[FIR_REG_0_NTL_LMD_POISON]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_LMD_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_LMD_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_LMD_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_LMD_POISON]

//>> GET_[FIR_REG_0_NTL_LMD_POISON]
static inline bool GET_FIR_REG_0_NTL_LMD_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_LMD_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_LMD_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_LMD_POISON]

//>> SET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_DATA_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_ARRAY_DATA_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]

//>> SET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_DATA_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_NTL_ARRAY_DATA_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]

//>> SET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_NTL_ARRAY_DATA_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_NTL_ARRAY_DATA_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]

//>> CLEAR_[FIR_REG_0_NTL_ARRAY_DATA_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_NTL_ARRAY_DATA_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_NTL_ARRAY_DATA_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_NTL_ARRAY_DATA_SUE]

//>> GET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_NTL_ARRAY_DATA_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_NTL_ARRAY_DATA_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]

//>> GET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]
static inline bool GET_FIR_REG_0_NTL_ARRAY_DATA_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_NTL_ARRAY_DATA_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_NTL_ARRAY_DATA_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_NTL_ARRAY_DATA_SUE]

//>> SET_[FIR_REG_0_CTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_ARRAY_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_ARRAY_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_ARRAY_CE]

//>> SET_[FIR_REG_0_CTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_ARRAY_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_ARRAY_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_ARRAY_CE]

//>> SET_[FIR_REG_0_CTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_ARRAY_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_ARRAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_ARRAY_CE]

//>> CLEAR_[FIR_REG_0_CTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_ARRAY_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_ARRAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_ARRAY_CE]

//>> GET_[FIR_REG_0_CTL_ARRAY_CE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_ARRAY_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_ARRAY_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_ARRAY_CE]

//>> GET_[FIR_REG_0_CTL_ARRAY_CE]
static inline bool GET_FIR_REG_0_CTL_ARRAY_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_ARRAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_ARRAY_CE]

//>> SET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_RECOV_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PBUS_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]

//>> SET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_RECOV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PBUS_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]

//>> SET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_RECOV_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_PBUS_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]

//>> CLEAR_[FIR_REG_0_CTL_PBUS_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_PBUS_RECOV_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_PBUS_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_PBUS_RECOV_ERR]

//>> GET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_PBUS_RECOV_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_PBUS_RECOV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]

//>> GET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]
static inline bool GET_FIR_REG_0_CTL_PBUS_RECOV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_PBUS_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PBUS_RECOV_ERR]

//>> SET_[FIR_REG_0_CTL_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_REG_RING_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_REG_RING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_REG_RING_ERR]

//>> SET_[FIR_REG_0_CTL_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_REG_RING_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_REG_RING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_REG_RING_ERR]

//>> SET_[FIR_REG_0_CTL_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_REG_RING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_REG_RING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_REG_RING_ERR]

//>> CLEAR_[FIR_REG_0_CTL_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_REG_RING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_REG_RING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_REG_RING_ERR]

//>> GET_[FIR_REG_0_CTL_REG_RING_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_REG_RING_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_REG_RING_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_REG_RING_ERR]

//>> GET_[FIR_REG_0_CTL_REG_RING_ERR]
static inline bool GET_FIR_REG_0_CTL_REG_RING_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_REG_RING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_REG_RING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_REG_RING_ERR]

//>> SET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_MMIO_ST_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_MMIO_ST_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_MMIO_ST_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]

//>> SET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_MMIO_ST_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_MMIO_ST_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_MMIO_ST_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]

//>> SET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_MMIO_ST_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_MMIO_ST_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_MMIO_ST_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]

//>> CLEAR_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_MMIO_ST_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_MMIO_ST_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_MMIO_ST_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]

//>> GET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_MMIO_ST_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_MMIO_ST_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_MMIO_ST_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]

//>> GET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]
static inline bool GET_FIR_REG_0_CTL_MMIO_ST_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_MMIO_ST_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_MMIO_ST_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_MMIO_ST_DATA_UE]

//>> SET_[FIR_REG_0_CTL_PEF]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PEF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PEF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_PEF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PEF]

//>> SET_[FIR_REG_0_CTL_PEF]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PEF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PEF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_PEF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PEF]

//>> SET_[FIR_REG_0_CTL_PEF]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PEF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_PEF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_PEF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PEF]

//>> CLEAR_[FIR_REG_0_CTL_PEF]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_PEF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_PEF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_PEF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_PEF]

//>> GET_[FIR_REG_0_CTL_PEF]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_PEF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_PEF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_PEF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PEF]

//>> GET_[FIR_REG_0_CTL_PEF]
static inline bool GET_FIR_REG_0_CTL_PEF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_PEF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_PEF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PEF]

//>> SET_[FIR_REG_0_CTL_NVL_CFG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_NVL_CFG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_NVL_CFG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_CFG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_NVL_CFG_ERR]

//>> SET_[FIR_REG_0_CTL_NVL_CFG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_NVL_CFG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_NVL_CFG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_CFG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_NVL_CFG_ERR]

//>> SET_[FIR_REG_0_CTL_NVL_CFG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_NVL_CFG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_NVL_CFG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_CFG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_NVL_CFG_ERR]

//>> CLEAR_[FIR_REG_0_CTL_NVL_CFG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_NVL_CFG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_NVL_CFG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_CFG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_NVL_CFG_ERR]

//>> GET_[FIR_REG_0_CTL_NVL_CFG_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_NVL_CFG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_NVL_CFG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_CFG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_NVL_CFG_ERR]

//>> GET_[FIR_REG_0_CTL_NVL_CFG_ERR]
static inline bool GET_FIR_REG_0_CTL_NVL_CFG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_NVL_CFG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_CFG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_NVL_CFG_ERR]

//>> SET_[FIR_REG_0_CTL_NVL_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_NVL_FATAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_NVL_FATAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_NVL_FATAL_ERR]

//>> SET_[FIR_REG_0_CTL_NVL_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_NVL_FATAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_NVL_FATAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_NVL_FATAL_ERR]

//>> SET_[FIR_REG_0_CTL_NVL_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_NVL_FATAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_NVL_FATAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_NVL_FATAL_ERR]

//>> CLEAR_[FIR_REG_0_CTL_NVL_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_NVL_FATAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_NVL_FATAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_NVL_FATAL_ERR]

//>> GET_[FIR_REG_0_CTL_NVL_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_NVL_FATAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_NVL_FATAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_NVL_FATAL_ERR]

//>> GET_[FIR_REG_0_CTL_NVL_FATAL_ERR]
static inline bool GET_FIR_REG_0_CTL_NVL_FATAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_NVL_FATAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_NVL_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_NVL_FATAL_ERR]

//>> SET_[FIR_REG_0_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_RESERVED_1]

//>> SET_[FIR_REG_0_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_RESERVED_1]

//>> SET_[FIR_REG_0_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_RESERVED_1]

//>> CLEAR_[FIR_REG_0_RESERVED_1]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_RESERVED_1]

//>> GET_[FIR_REG_0_RESERVED_1]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_RESERVED_1]

//>> GET_[FIR_REG_0_RESERVED_1]
static inline bool GET_FIR_REG_0_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_RESERVED_1]

//>> SET_[FIR_REG_0_CTL_ARRAY_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_ARRAY_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_ARRAY_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_ARRAY_UE]

//>> SET_[FIR_REG_0_CTL_ARRAY_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_ARRAY_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_ARRAY_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_ARRAY_UE]

//>> SET_[FIR_REG_0_CTL_ARRAY_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_ARRAY_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_ARRAY_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_ARRAY_UE]

//>> CLEAR_[FIR_REG_0_CTL_ARRAY_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_ARRAY_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_ARRAY_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_ARRAY_UE]

//>> GET_[FIR_REG_0_CTL_ARRAY_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_ARRAY_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_ARRAY_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_ARRAY_UE]

//>> GET_[FIR_REG_0_CTL_ARRAY_UE]
static inline bool GET_FIR_REG_0_CTL_ARRAY_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_ARRAY_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_ARRAY_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_ARRAY_UE]

//>> SET_[FIR_REG_0_CTL_PBUS_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PBUS_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_PERR]

//>> SET_[FIR_REG_0_CTL_PBUS_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PBUS_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_PERR]

//>> SET_[FIR_REG_0_CTL_PBUS_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_PBUS_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_PERR]

//>> CLEAR_[FIR_REG_0_CTL_PBUS_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_PBUS_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_PBUS_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_PBUS_PERR]

//>> GET_[FIR_REG_0_CTL_PBUS_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_PBUS_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_PBUS_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PBUS_PERR]

//>> GET_[FIR_REG_0_CTL_PBUS_PERR]
static inline bool GET_FIR_REG_0_CTL_PBUS_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_PBUS_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PBUS_PERR]

//>> SET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_FATAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PBUS_FATAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]

//>> SET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_FATAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PBUS_FATAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]

//>> SET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_FATAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_PBUS_FATAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]

//>> CLEAR_[FIR_REG_0_CTL_PBUS_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_PBUS_FATAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_PBUS_FATAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_PBUS_FATAL_ERR]

//>> GET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_PBUS_FATAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_PBUS_FATAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]

//>> GET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]
static inline bool GET_FIR_REG_0_CTL_PBUS_FATAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_PBUS_FATAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_FATAL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PBUS_FATAL_ERR]

//>> SET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_CONFIG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PBUS_CONFIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]

//>> SET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_CONFIG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_PBUS_CONFIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]

//>> SET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_PBUS_CONFIG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_PBUS_CONFIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]

//>> CLEAR_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_PBUS_CONFIG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_PBUS_CONFIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]

//>> GET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_PBUS_CONFIG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_PBUS_CONFIG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]

//>> GET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]
static inline bool GET_FIR_REG_0_CTL_PBUS_CONFIG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_PBUS_CONFIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_PBUS_CONFIG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_PBUS_CONFIG_ERR]

//>> SET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_FWD_PROGRESS_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_FWD_PROGRESS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_FWD_PROGRESS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]

//>> SET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_FWD_PROGRESS_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_FWD_PROGRESS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_FWD_PROGRESS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]

//>> SET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_FWD_PROGRESS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_FWD_PROGRESS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_FWD_PROGRESS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]

//>> CLEAR_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_FWD_PROGRESS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_FWD_PROGRESS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_FWD_PROGRESS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]

//>> GET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_FWD_PROGRESS_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_FWD_PROGRESS_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_FWD_PROGRESS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]

//>> GET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]
static inline bool GET_FIR_REG_0_CTL_FWD_PROGRESS_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_FWD_PROGRESS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_FWD_PROGRESS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_FWD_PROGRESS_ERR]

//>> SET_[FIR_REG_0_CTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_LOGIC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_LOGIC_ERR]

//>> SET_[FIR_REG_0_CTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_LOGIC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_LOGIC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_LOGIC_ERR]

//>> SET_[FIR_REG_0_CTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_LOGIC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_LOGIC_ERR]

//>> CLEAR_[FIR_REG_0_CTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_LOGIC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_LOGIC_ERR]

//>> GET_[FIR_REG_0_CTL_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_LOGIC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_LOGIC_ERR]

//>> GET_[FIR_REG_0_CTL_LOGIC_ERR]
static inline bool GET_FIR_REG_0_CTL_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_LOGIC_ERR]

//>> SET_[FIR_REG_0_CTL_RSVD_14]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_RSVD_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_RSVD_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_RSVD_14]

//>> SET_[FIR_REG_0_CTL_RSVD_14]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_RSVD_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_RSVD_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_RSVD_14]

//>> SET_[FIR_REG_0_CTL_RSVD_14]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_RSVD_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_RSVD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_RSVD_14]

//>> CLEAR_[FIR_REG_0_CTL_RSVD_14]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_RSVD_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_RSVD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_RSVD_14]

//>> GET_[FIR_REG_0_CTL_RSVD_14]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_RSVD_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_RSVD_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_RSVD_14]

//>> GET_[FIR_REG_0_CTL_RSVD_14]
static inline bool GET_FIR_REG_0_CTL_RSVD_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_RSVD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_RSVD_14]

//>> SET_[FIR_REG_0_CTL_RSVD_15]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_RSVD_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_RSVD_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_RSVD_15]

//>> SET_[FIR_REG_0_CTL_RSVD_15]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_RSVD_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_CTL_RSVD_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_RSVD_15]

//>> SET_[FIR_REG_0_CTL_RSVD_15]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_CTL_RSVD_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_CTL_RSVD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_CTL_RSVD_15]

//>> CLEAR_[FIR_REG_0_CTL_RSVD_15]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_CTL_RSVD_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_CTL_RSVD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_CTL_RSVD_15]

//>> GET_[FIR_REG_0_CTL_RSVD_15]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_CTL_RSVD_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_CTL_RSVD_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_RSVD_15]

//>> GET_[FIR_REG_0_CTL_RSVD_15]
static inline bool GET_FIR_REG_0_CTL_RSVD_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_CTL_RSVD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_CTL_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_CTL_RSVD_15]

//>> SET_[FIR_REG_0_DAT_DATA_BE_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_DATA_BE_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_UE]

//>> SET_[FIR_REG_0_DAT_DATA_BE_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_DATA_BE_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_UE]

//>> SET_[FIR_REG_0_DAT_DATA_BE_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_DATA_BE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_UE]

//>> CLEAR_[FIR_REG_0_DAT_DATA_BE_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_DATA_BE_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_DATA_BE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_DATA_BE_UE]

//>> GET_[FIR_REG_0_DAT_DATA_BE_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_DATA_BE_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_DATA_BE_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_DATA_BE_UE]

//>> GET_[FIR_REG_0_DAT_DATA_BE_UE]
static inline bool GET_FIR_REG_0_DAT_DATA_BE_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_DATA_BE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_DATA_BE_UE]

//>> SET_[FIR_REG_0_DAT_DATA_BE_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_DATA_BE_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_CE]

//>> SET_[FIR_REG_0_DAT_DATA_BE_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_DATA_BE_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_CE]

//>> SET_[FIR_REG_0_DAT_DATA_BE_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_DATA_BE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_CE]

//>> CLEAR_[FIR_REG_0_DAT_DATA_BE_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_DATA_BE_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_DATA_BE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_DATA_BE_CE]

//>> GET_[FIR_REG_0_DAT_DATA_BE_CE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_DATA_BE_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_DATA_BE_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_DATA_BE_CE]

//>> GET_[FIR_REG_0_DAT_DATA_BE_CE]
static inline bool GET_FIR_REG_0_DAT_DATA_BE_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_DATA_BE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_DATA_BE_CE]

//>> SET_[FIR_REG_0_DAT_DATA_BE_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_DATA_BE_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_PERR]

//>> SET_[FIR_REG_0_DAT_DATA_BE_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_DATA_BE_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_PERR]

//>> SET_[FIR_REG_0_DAT_DATA_BE_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_DATA_BE_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_PERR]

//>> CLEAR_[FIR_REG_0_DAT_DATA_BE_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_DATA_BE_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_DATA_BE_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_DATA_BE_PERR]

//>> GET_[FIR_REG_0_DAT_DATA_BE_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_DATA_BE_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_DATA_BE_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_DATA_BE_PERR]

//>> GET_[FIR_REG_0_DAT_DATA_BE_PERR]
static inline bool GET_FIR_REG_0_DAT_DATA_BE_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_DATA_BE_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_DATA_BE_PERR]

//>> SET_[FIR_REG_0_DAT_CREG_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_CREG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_CREG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_CREG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_CREG_PERR]

//>> SET_[FIR_REG_0_DAT_CREG_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_CREG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_CREG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_CREG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_CREG_PERR]

//>> SET_[FIR_REG_0_DAT_CREG_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_CREG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_CREG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_CREG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_CREG_PERR]

//>> CLEAR_[FIR_REG_0_DAT_CREG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_CREG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_CREG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_CREG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_CREG_PERR]

//>> GET_[FIR_REG_0_DAT_CREG_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_CREG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_CREG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_CREG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_CREG_PERR]

//>> GET_[FIR_REG_0_DAT_CREG_PERR]
static inline bool GET_FIR_REG_0_DAT_CREG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_CREG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_CREG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_CREG_PERR]

//>> SET_[FIR_REG_0_DAT_RTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_RTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_RTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RTAG_PERR]

//>> SET_[FIR_REG_0_DAT_RTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_RTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_RTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RTAG_PERR]

//>> SET_[FIR_REG_0_DAT_RTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_RTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_RTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RTAG_PERR]

//>> CLEAR_[FIR_REG_0_DAT_RTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_RTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_RTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_RTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_RTAG_PERR]

//>> GET_[FIR_REG_0_DAT_RTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_RTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_RTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_RTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_RTAG_PERR]

//>> GET_[FIR_REG_0_DAT_RTAG_PERR]
static inline bool GET_FIR_REG_0_DAT_RTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_RTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_RTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_RTAG_PERR]

//>> SET_[FIR_REG_0_DAT_STATE_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_STATE_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_STATE_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_STATE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_STATE_PERR]

//>> SET_[FIR_REG_0_DAT_STATE_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_STATE_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_STATE_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_STATE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_STATE_PERR]

//>> SET_[FIR_REG_0_DAT_STATE_PERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_STATE_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_STATE_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_STATE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_STATE_PERR]

//>> CLEAR_[FIR_REG_0_DAT_STATE_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_STATE_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_STATE_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_STATE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_STATE_PERR]

//>> GET_[FIR_REG_0_DAT_STATE_PERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_STATE_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_STATE_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_STATE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_STATE_PERR]

//>> GET_[FIR_REG_0_DAT_STATE_PERR]
static inline bool GET_FIR_REG_0_DAT_STATE_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_STATE_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_STATE_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_STATE_PERR]

//>> SET_[FIR_REG_0_DAT_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_LOGIC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_LOGIC_ERR]

//>> SET_[FIR_REG_0_DAT_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_LOGIC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_LOGIC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_LOGIC_ERR]

//>> SET_[FIR_REG_0_DAT_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_LOGIC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_LOGIC_ERR]

//>> CLEAR_[FIR_REG_0_DAT_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_LOGIC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_LOGIC_ERR]

//>> GET_[FIR_REG_0_DAT_LOGIC_ERR]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_LOGIC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_LOGIC_ERR]

//>> GET_[FIR_REG_0_DAT_LOGIC_ERR]
static inline bool GET_FIR_REG_0_DAT_LOGIC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_LOGIC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_LOGIC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_LOGIC_ERR]

//>> SET_[FIR_REG_0_DAT_DATA_BE_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_DATA_BE_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_SUE]

//>> SET_[FIR_REG_0_DAT_DATA_BE_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_DATA_BE_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_SUE]

//>> SET_[FIR_REG_0_DAT_DATA_BE_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_DATA_BE_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_DATA_BE_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_DATA_BE_SUE]

//>> CLEAR_[FIR_REG_0_DAT_DATA_BE_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_DATA_BE_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_DATA_BE_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_DATA_BE_SUE]

//>> GET_[FIR_REG_0_DAT_DATA_BE_SUE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_DATA_BE_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_DATA_BE_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_DATA_BE_SUE]

//>> GET_[FIR_REG_0_DAT_DATA_BE_SUE]
static inline bool GET_FIR_REG_0_DAT_DATA_BE_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_DATA_BE_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_DATA_BE_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_DATA_BE_SUE]

//>> SET_[FIR_REG_0_DAT_PBRX_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_PBRX_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_PBRX_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_PBRX_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_PBRX_SUE]

//>> SET_[FIR_REG_0_DAT_PBRX_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_PBRX_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_PBRX_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_PBRX_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_PBRX_SUE]

//>> SET_[FIR_REG_0_DAT_PBRX_SUE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_PBRX_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_PBRX_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_PBRX_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_PBRX_SUE]

//>> CLEAR_[FIR_REG_0_DAT_PBRX_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_PBRX_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_PBRX_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_PBRX_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_PBRX_SUE]

//>> GET_[FIR_REG_0_DAT_PBRX_SUE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_PBRX_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_PBRX_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_PBRX_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_PBRX_SUE]

//>> GET_[FIR_REG_0_DAT_PBRX_SUE]
static inline bool GET_FIR_REG_0_DAT_PBRX_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_PBRX_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_PBRX_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_PBRX_SUE]

//>> SET_[FIR_REG_0_DAT_RSVD_9]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RSVD_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_RSVD_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RSVD_9]

//>> SET_[FIR_REG_0_DAT_RSVD_9]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RSVD_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_RSVD_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RSVD_9]

//>> SET_[FIR_REG_0_DAT_RSVD_9]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RSVD_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_RSVD_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RSVD_9]

//>> CLEAR_[FIR_REG_0_DAT_RSVD_9]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_RSVD_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_RSVD_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_RSVD_9]

//>> GET_[FIR_REG_0_DAT_RSVD_9]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_RSVD_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_RSVD_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_RSVD_9]

//>> GET_[FIR_REG_0_DAT_RSVD_9]
static inline bool GET_FIR_REG_0_DAT_RSVD_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_RSVD_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_RSVD_9]

//>> SET_[FIR_REG_0_DAT_RSVD_10]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RSVD_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_RSVD_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RSVD_10]

//>> SET_[FIR_REG_0_DAT_RSVD_10]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RSVD_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_DAT_RSVD_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RSVD_10]

//>> SET_[FIR_REG_0_DAT_RSVD_10]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_DAT_RSVD_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_DAT_RSVD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_DAT_RSVD_10]

//>> CLEAR_[FIR_REG_0_DAT_RSVD_10]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_DAT_RSVD_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_DAT_RSVD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_DAT_RSVD_10]

//>> GET_[FIR_REG_0_DAT_RSVD_10]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_DAT_RSVD_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_DAT_RSVD_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_RSVD_10]

//>> GET_[FIR_REG_0_DAT_RSVD_10]
static inline bool GET_FIR_REG_0_DAT_RSVD_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_DAT_RSVD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_DAT_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_DAT_RSVD_10]

//>> SET_[FIR_REG_0_XTS_INT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_INT]

//>> SET_[FIR_REG_0_XTS_INT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_INT]

//>> SET_[FIR_REG_0_XTS_INT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_INT]

//>> CLEAR_[FIR_REG_0_XTS_INT]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_INT]

//>> GET_[FIR_REG_0_XTS_INT]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_INT]

//>> GET_[FIR_REG_0_XTS_INT]
static inline bool GET_FIR_REG_0_XTS_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_INT]

//>> SET_[FIR_REG_0_XTS_SRAM_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_SRAM_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_SRAM_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_SRAM_CE]

//>> SET_[FIR_REG_0_XTS_SRAM_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_SRAM_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_SRAM_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_SRAM_CE]

//>> SET_[FIR_REG_0_XTS_SRAM_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_SRAM_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_SRAM_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_SRAM_CE]

//>> CLEAR_[FIR_REG_0_XTS_SRAM_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_SRAM_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_SRAM_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_SRAM_CE]

//>> GET_[FIR_REG_0_XTS_SRAM_CE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_SRAM_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_SRAM_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_SRAM_CE]

//>> GET_[FIR_REG_0_XTS_SRAM_CE]
static inline bool GET_FIR_REG_0_XTS_SRAM_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_SRAM_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_SRAM_CE]

//>> SET_[FIR_REG_0_XTS_SRAM_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_SRAM_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_SRAM_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_SRAM_UE]

//>> SET_[FIR_REG_0_XTS_SRAM_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_SRAM_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_SRAM_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_SRAM_UE]

//>> SET_[FIR_REG_0_XTS_SRAM_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_SRAM_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_SRAM_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_SRAM_UE]

//>> CLEAR_[FIR_REG_0_XTS_SRAM_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_SRAM_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_SRAM_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_SRAM_UE]

//>> GET_[FIR_REG_0_XTS_SRAM_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_SRAM_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_SRAM_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_SRAM_UE]

//>> GET_[FIR_REG_0_XTS_SRAM_UE]
static inline bool GET_FIR_REG_0_XTS_SRAM_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_SRAM_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_SRAM_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_SRAM_UE]

//>> SET_[FIR_REG_0_XTS_PROTOCOL_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PROTOCOL_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_PROTOCOL_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PROTOCOL_CE]

//>> SET_[FIR_REG_0_XTS_PROTOCOL_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PROTOCOL_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_PROTOCOL_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PROTOCOL_CE]

//>> SET_[FIR_REG_0_XTS_PROTOCOL_CE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PROTOCOL_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_PROTOCOL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PROTOCOL_CE]

//>> CLEAR_[FIR_REG_0_XTS_PROTOCOL_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_PROTOCOL_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_PROTOCOL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_PROTOCOL_CE]

//>> GET_[FIR_REG_0_XTS_PROTOCOL_CE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_PROTOCOL_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_PROTOCOL_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_PROTOCOL_CE]

//>> GET_[FIR_REG_0_XTS_PROTOCOL_CE]
static inline bool GET_FIR_REG_0_XTS_PROTOCOL_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_PROTOCOL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_PROTOCOL_CE]

//>> SET_[FIR_REG_0_XTS_PROTOCOL_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PROTOCOL_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_PROTOCOL_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PROTOCOL_UE]

//>> SET_[FIR_REG_0_XTS_PROTOCOL_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PROTOCOL_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_PROTOCOL_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PROTOCOL_UE]

//>> SET_[FIR_REG_0_XTS_PROTOCOL_UE]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PROTOCOL_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_PROTOCOL_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PROTOCOL_UE]

//>> CLEAR_[FIR_REG_0_XTS_PROTOCOL_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_PROTOCOL_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_PROTOCOL_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_PROTOCOL_UE]

//>> GET_[FIR_REG_0_XTS_PROTOCOL_UE]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_PROTOCOL_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_PROTOCOL_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_PROTOCOL_UE]

//>> GET_[FIR_REG_0_XTS_PROTOCOL_UE]
static inline bool GET_FIR_REG_0_XTS_PROTOCOL_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_PROTOCOL_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_PROTOCOL_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_PROTOCOL_UE]

//>> SET_[FIR_REG_0_XTS_PBUS_PROTOCOL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PBUS_PROTOCOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_PBUS_PROTOCOL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_PBUS_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PBUS_PROTOCOL]

//>> SET_[FIR_REG_0_XTS_PBUS_PROTOCOL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PBUS_PROTOCOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_PBUS_PROTOCOL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_PBUS_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PBUS_PROTOCOL]

//>> SET_[FIR_REG_0_XTS_PBUS_PROTOCOL]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_PBUS_PROTOCOL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_PBUS_PROTOCOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_PBUS_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_PBUS_PROTOCOL]

//>> CLEAR_[FIR_REG_0_XTS_PBUS_PROTOCOL]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_PBUS_PROTOCOL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_PBUS_PROTOCOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_PBUS_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_PBUS_PROTOCOL]

//>> GET_[FIR_REG_0_XTS_PBUS_PROTOCOL]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_PBUS_PROTOCOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_PBUS_PROTOCOL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_PBUS_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_PBUS_PROTOCOL]

//>> GET_[FIR_REG_0_XTS_PBUS_PROTOCOL]
static inline bool GET_FIR_REG_0_XTS_PBUS_PROTOCOL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_PBUS_PROTOCOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_PBUS_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_PBUS_PROTOCOL]

//>> SET_[FIR_REG_0_XTS_RSVD_6]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_6]

//>> SET_[FIR_REG_0_XTS_RSVD_6]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_6]

//>> SET_[FIR_REG_0_XTS_RSVD_6]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_6]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_6]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_6]

//>> GET_[FIR_REG_0_XTS_RSVD_6]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_6]

//>> GET_[FIR_REG_0_XTS_RSVD_6]
static inline bool GET_FIR_REG_0_XTS_RSVD_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_6]

//>> SET_[FIR_REG_0_XTS_EARLY_HANG_WARN]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_EARLY_HANG_WARN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_EARLY_HANG_WARN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_EARLY_HANG_WARN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_EARLY_HANG_WARN]

//>> SET_[FIR_REG_0_XTS_EARLY_HANG_WARN]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_EARLY_HANG_WARN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_EARLY_HANG_WARN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_EARLY_HANG_WARN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_EARLY_HANG_WARN]

//>> SET_[FIR_REG_0_XTS_EARLY_HANG_WARN]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_EARLY_HANG_WARN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_EARLY_HANG_WARN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_EARLY_HANG_WARN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_EARLY_HANG_WARN]

//>> CLEAR_[FIR_REG_0_XTS_EARLY_HANG_WARN]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_EARLY_HANG_WARN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_EARLY_HANG_WARN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_EARLY_HANG_WARN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_EARLY_HANG_WARN]

//>> GET_[FIR_REG_0_XTS_EARLY_HANG_WARN]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_EARLY_HANG_WARN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_EARLY_HANG_WARN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_EARLY_HANG_WARN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_EARLY_HANG_WARN]

//>> GET_[FIR_REG_0_XTS_EARLY_HANG_WARN]
static inline bool GET_FIR_REG_0_XTS_EARLY_HANG_WARN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_EARLY_HANG_WARN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_EARLY_HANG_WARN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_EARLY_HANG_WARN]

//>> SET_[FIR_REG_0_XTS_RSVD_8]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_8]

//>> SET_[FIR_REG_0_XTS_RSVD_8]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_8]

//>> SET_[FIR_REG_0_XTS_RSVD_8]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_8]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_8]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_8]

//>> GET_[FIR_REG_0_XTS_RSVD_8]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_8]

//>> GET_[FIR_REG_0_XTS_RSVD_8]
static inline bool GET_FIR_REG_0_XTS_RSVD_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_8]

//>> SET_[FIR_REG_0_XTS_RSVD_9]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_9]

//>> SET_[FIR_REG_0_XTS_RSVD_9]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_9]

//>> SET_[FIR_REG_0_XTS_RSVD_9]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_9]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_9]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_9]

//>> GET_[FIR_REG_0_XTS_RSVD_9]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_9]

//>> GET_[FIR_REG_0_XTS_RSVD_9]
static inline bool GET_FIR_REG_0_XTS_RSVD_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_9]

//>> SET_[FIR_REG_0_XTS_RSVD_10]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_10]

//>> SET_[FIR_REG_0_XTS_RSVD_10]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_10]

//>> SET_[FIR_REG_0_XTS_RSVD_10]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_10]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_10]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_10]

//>> GET_[FIR_REG_0_XTS_RSVD_10]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_10]

//>> GET_[FIR_REG_0_XTS_RSVD_10]
static inline bool GET_FIR_REG_0_XTS_RSVD_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_10]

//>> SET_[FIR_REG_0_XTS_RSVD_11]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_11]

//>> SET_[FIR_REG_0_XTS_RSVD_11]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_11]

//>> SET_[FIR_REG_0_XTS_RSVD_11]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_11]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_11]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_11]

//>> GET_[FIR_REG_0_XTS_RSVD_11]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_11]

//>> GET_[FIR_REG_0_XTS_RSVD_11]
static inline bool GET_FIR_REG_0_XTS_RSVD_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_11]

//>> SET_[FIR_REG_0_XTS_RSVD_12]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_12]

//>> SET_[FIR_REG_0_XTS_RSVD_12]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_12]

//>> SET_[FIR_REG_0_XTS_RSVD_12]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_12]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_12]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_12]

//>> GET_[FIR_REG_0_XTS_RSVD_12]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_12]

//>> GET_[FIR_REG_0_XTS_RSVD_12]
static inline bool GET_FIR_REG_0_XTS_RSVD_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_12]

//>> SET_[FIR_REG_0_XTS_RSVD_13]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_13]

//>> SET_[FIR_REG_0_XTS_RSVD_13]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_13]

//>> SET_[FIR_REG_0_XTS_RSVD_13]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_13]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_13]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_13]

//>> GET_[FIR_REG_0_XTS_RSVD_13]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_13]

//>> GET_[FIR_REG_0_XTS_RSVD_13]
static inline bool GET_FIR_REG_0_XTS_RSVD_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_13]

//>> SET_[FIR_REG_0_XTS_RSVD_14]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_14]

//>> SET_[FIR_REG_0_XTS_RSVD_14]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_14]

//>> SET_[FIR_REG_0_XTS_RSVD_14]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_14]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_14]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_14]

//>> GET_[FIR_REG_0_XTS_RSVD_14]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_14]

//>> GET_[FIR_REG_0_XTS_RSVD_14]
static inline bool GET_FIR_REG_0_XTS_RSVD_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_14]

//>> SET_[FIR_REG_0_XTS_RSVD_15]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_15]

//>> SET_[FIR_REG_0_XTS_RSVD_15]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_15]

//>> SET_[FIR_REG_0_XTS_RSVD_15]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_15]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_15]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_15]

//>> GET_[FIR_REG_0_XTS_RSVD_15]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_15]

//>> GET_[FIR_REG_0_XTS_RSVD_15]
static inline bool GET_FIR_REG_0_XTS_RSVD_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_15]

//>> SET_[FIR_REG_0_XTS_RSVD_16]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_16]

//>> SET_[FIR_REG_0_XTS_RSVD_16]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_16]

//>> SET_[FIR_REG_0_XTS_RSVD_16]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_16]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_16]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_16]

//>> GET_[FIR_REG_0_XTS_RSVD_16]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_16]

//>> GET_[FIR_REG_0_XTS_RSVD_16]
static inline bool GET_FIR_REG_0_XTS_RSVD_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_16]

//>> SET_[FIR_REG_0_XTS_RSVD_17]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_17]

//>> SET_[FIR_REG_0_XTS_RSVD_17]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_17]

//>> SET_[FIR_REG_0_XTS_RSVD_17]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_17]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_17]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_17]

//>> GET_[FIR_REG_0_XTS_RSVD_17]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_17]

//>> GET_[FIR_REG_0_XTS_RSVD_17]
static inline bool GET_FIR_REG_0_XTS_RSVD_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_17]

//>> SET_[FIR_REG_0_XTS_RSVD_18]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_18]

//>> SET_[FIR_REG_0_XTS_RSVD_18]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_XTS_RSVD_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_18]

//>> SET_[FIR_REG_0_XTS_RSVD_18]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_XTS_RSVD_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_XTS_RSVD_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_XTS_RSVD_18]

//>> CLEAR_[FIR_REG_0_XTS_RSVD_18]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_XTS_RSVD_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_XTS_RSVD_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_XTS_RSVD_18]

//>> GET_[FIR_REG_0_XTS_RSVD_18]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_XTS_RSVD_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_XTS_RSVD_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_18]

//>> GET_[FIR_REG_0_XTS_RSVD_18]
static inline bool GET_FIR_REG_0_XTS_RSVD_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_XTS_RSVD_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_XTS_RSVD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_XTS_RSVD_18]

//>> SET_[FIR_REG_0_AME_RSVD_INT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_AME_RSVD_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_INT]

//>> SET_[FIR_REG_0_AME_RSVD_INT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_AME_RSVD_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_INT]

//>> SET_[FIR_REG_0_AME_RSVD_INT]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_AME_RSVD_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_INT]

//>> CLEAR_[FIR_REG_0_AME_RSVD_INT]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_AME_RSVD_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_AME_RSVD_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_AME_RSVD_INT]

//>> GET_[FIR_REG_0_AME_RSVD_INT]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_AME_RSVD_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_AME_RSVD_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_AME_RSVD_INT]

//>> GET_[FIR_REG_0_AME_RSVD_INT]
static inline bool GET_FIR_REG_0_AME_RSVD_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_AME_RSVD_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_AME_RSVD_INT]

//>> SET_[FIR_REG_0_AME_RSVD_0]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_AME_RSVD_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_0]

//>> SET_[FIR_REG_0_AME_RSVD_0]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_AME_RSVD_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_0]

//>> SET_[FIR_REG_0_AME_RSVD_0]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_AME_RSVD_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_0]

//>> CLEAR_[FIR_REG_0_AME_RSVD_0]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_AME_RSVD_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_AME_RSVD_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_AME_RSVD_0]

//>> GET_[FIR_REG_0_AME_RSVD_0]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_AME_RSVD_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_AME_RSVD_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_AME_RSVD_0]

//>> GET_[FIR_REG_0_AME_RSVD_0]
static inline bool GET_FIR_REG_0_AME_RSVD_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_AME_RSVD_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_AME_RSVD_0]

//>> SET_[FIR_REG_0_AME_RSVD_1]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_AME_RSVD_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_1]

//>> SET_[FIR_REG_0_AME_RSVD_1]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_AME_RSVD_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_1]

//>> SET_[FIR_REG_0_AME_RSVD_1]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_AME_RSVD_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_AME_RSVD_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_AME_RSVD_1]

//>> CLEAR_[FIR_REG_0_AME_RSVD_1]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_AME_RSVD_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_AME_RSVD_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_AME_RSVD_1]

//>> GET_[FIR_REG_0_AME_RSVD_1]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_AME_RSVD_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_AME_RSVD_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_AME_RSVD_1]

//>> GET_[FIR_REG_0_AME_RSVD_1]
static inline bool GET_FIR_REG_0_AME_RSVD_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_AME_RSVD_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_AME_RSVD_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_AME_RSVD_1]

//>> SET_[FIR_REG_0_FIR0_RSVD_62]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_FIR0_RSVD_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_FIR0_RSVD_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_FIR0_RSVD_62]

//>> SET_[FIR_REG_0_FIR0_RSVD_62]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_FIR0_RSVD_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_FIR0_RSVD_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_FIR0_RSVD_62]

//>> SET_[FIR_REG_0_FIR0_RSVD_62]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_FIR0_RSVD_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_FIR0_RSVD_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_FIR0_RSVD_62]

//>> CLEAR_[FIR_REG_0_FIR0_RSVD_62]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_FIR0_RSVD_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_FIR0_RSVD_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_FIR0_RSVD_62]

//>> GET_[FIR_REG_0_FIR0_RSVD_62]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_FIR0_RSVD_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_FIR0_RSVD_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_FIR0_RSVD_62]

//>> GET_[FIR_REG_0_FIR0_RSVD_62]
static inline bool GET_FIR_REG_0_FIR0_RSVD_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_FIR0_RSVD_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_FIR0_RSVD_62]

//>> SET_[FIR_REG_0_FIR0_RSVD_63]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_FIR0_RSVD_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_FIR0_RSVD_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_FIR0_RSVD_63]

//>> SET_[FIR_REG_0_FIR0_RSVD_63]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_FIR0_RSVD_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.insertFromRight<FIR_REG_0_FIR0_RSVD_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_FIR0_RSVD_63]

//>> SET_[FIR_REG_0_FIR0_RSVD_63]
static inline fapi2::buffer<uint64_t>& SET_FIR_REG_0_FIR0_RSVD_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.setBit<FIR_REG_0_FIR0_RSVD_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FIR_REG_0_FIR0_RSVD_63]

//>> CLEAR_[FIR_REG_0_FIR0_RSVD_63]
static inline fapi2::buffer<uint64_t>& CLEAR_FIR_REG_0_FIR0_RSVD_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return o_data.clearBit<FIR_REG_0_FIR0_RSVD_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FIR_REG_0_FIR0_RSVD_63]

//>> GET_[FIR_REG_0_FIR0_RSVD_63]
static inline fapi2::buffer<uint64_t>& GET_FIR_REG_0_FIR0_RSVD_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.extractToRight<FIR_REG_0_FIR0_RSVD_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_FIR0_RSVD_63]

//>> GET_[FIR_REG_0_FIR0_RSVD_63]
static inline bool GET_FIR_REG_0_FIR0_RSVD_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR_REG_0_RW, FIR_REG_0_WO_AND, FIR_REG_0_WO_OR));
#endif
    return i_data.getBit<FIR_REG_0_FIR0_RSVD_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access FIR_REG_0_FIR0_RSVD_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FIR_REG_0_FIR0_RSVD_63]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
