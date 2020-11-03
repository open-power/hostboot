/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00006.H $          */
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

#ifndef __PAU_REG00006_H_
#define __PAU_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[CS_CTL_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_CTL_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_GPU0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_CTL_MISC_GPU0_BAR]

//>> GET_[CS_CTL_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_CTL_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_GPU0_BAR;
#endif
    return fapi2::getScom(i_target, CS_CTL_MISC_GPU0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR]

//>> PUT_[CS_CTL_MISC_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_CTL_MISC_GPU0_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return fapi2::putScom(i_target, CS_CTL_MISC_GPU0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_CTL_MISC_GPU0_BAR]


//>> SET_[CS_CTL_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_ENABLE]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_ENABLE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_ENABLE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_ENABLE]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_ENABLE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_ADDR_MASK,
           CS_CTL_MISC_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_ADDR_MASK]

//>> SET_[CS_CTL_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_ADDR_MASK,
           CS_CTL_MISC_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_ADDR_MASK]

//>> GET_[CS_CTL_MISC_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_ADDR_MASK,
           CS_CTL_MISC_GPU0_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_ADDR_MASK]

//>> SET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_SL_MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_SL_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]

//>> GET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]

//>> GET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_4T_LIMIT]

//>> SET_[CS_CTL_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_4T_SELECT,
           CS_CTL_MISC_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_4T_SELECT]

//>> SET_[CS_CTL_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_4T_SELECT,
           CS_CTL_MISC_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_4T_SELECT]

//>> GET_[CS_CTL_MISC_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_4T_SELECT,
           CS_CTL_MISC_GPU0_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_4T_SELECT]

//>> SET_[CS_CTL_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_MODE,
           CS_CTL_MISC_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_MODE,
           CS_CTL_MISC_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_MODE,
           CS_CTL_MISC_GPU0_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_GRANULE]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_GRANULE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_GRANULE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_GRANULE]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_GRANULE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_POISON]

//>> SET_[CS_CTL_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_POISON]

//>> SET_[CS_CTL_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_POISON]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_POISON]

//>> GET_[CS_CTL_MISC_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_POISON]

//>> GET_[CS_CTL_MISC_GPU0_BAR_POISON]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_POISON]

//>> SET_[CS_CTL_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_M2MODE]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_M2MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_M2MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_M2MODE]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_M2MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]

//>> GET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]

//>> GET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_SECURE_A12]

//>> SET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]

//>> GET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_EXTENDED_MODE]

//>> SET_[CS_CTL_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_RESERVED]

//>> SET_[CS_CTL_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_RESERVED]

//>> SET_[CS_CTL_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU0_BAR_RESERVED]

//>> CLEAR_[CS_CTL_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU0_BAR_RESERVED]

//>> GET_[CS_CTL_MISC_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU0_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_RESERVED]

//>> GET_[CS_CTL_MISC_GPU0_BAR_RESERVED]
static inline bool GET_CS_CTL_MISC_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU0_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU0_BAR_RESERVED]

//>> PREP_[CS_CTL_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_CTL_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_GPU1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_CTL_MISC_GPU1_BAR]

//>> GET_[CS_CTL_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_CTL_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_CTL_MISC_GPU1_BAR;
#endif
    return fapi2::getScom(i_target, CS_CTL_MISC_GPU1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR]

//>> PUT_[CS_CTL_MISC_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_CTL_MISC_GPU1_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return fapi2::putScom(i_target, CS_CTL_MISC_GPU1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_CTL_MISC_GPU1_BAR]


//>> SET_[CS_CTL_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_ENABLE]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_ENABLE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_ENABLE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_ENABLE]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_ENABLE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_ADDR_MASK,
           CS_CTL_MISC_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_ADDR_MASK]

//>> SET_[CS_CTL_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_ADDR_MASK,
           CS_CTL_MISC_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_ADDR_MASK]

//>> GET_[CS_CTL_MISC_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_ADDR_MASK,
           CS_CTL_MISC_GPU1_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_ADDR_MASK]

//>> SET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_SL_MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_SL_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]

//>> GET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]

//>> GET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_4T_LIMIT]

//>> SET_[CS_CTL_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_4T_SELECT,
           CS_CTL_MISC_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_4T_SELECT]

//>> SET_[CS_CTL_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_4T_SELECT,
           CS_CTL_MISC_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_4T_SELECT]

//>> GET_[CS_CTL_MISC_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_4T_SELECT,
           CS_CTL_MISC_GPU1_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_4T_SELECT]

//>> SET_[CS_CTL_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_MODE,
           CS_CTL_MISC_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_MODE,
           CS_CTL_MISC_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_MODE,
           CS_CTL_MISC_GPU1_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_GRANULE]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_GRANULE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_GRANULE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_GRANULE]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_GRANULE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_POISON]

//>> SET_[CS_CTL_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_POISON]

//>> SET_[CS_CTL_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_POISON]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_POISON]

//>> GET_[CS_CTL_MISC_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_POISON]

//>> GET_[CS_CTL_MISC_GPU1_BAR_POISON]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_POISON]

//>> SET_[CS_CTL_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_M2MODE]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_M2MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_M2MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_M2MODE]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_M2MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]

//>> GET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]

//>> GET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_SECURE_A12]

//>> SET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]

//>> GET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_EXTENDED_MODE]

//>> SET_[CS_CTL_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_RESERVED]

//>> SET_[CS_CTL_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.insertFromRight<CS_CTL_MISC_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_RESERVED]

//>> SET_[CS_CTL_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_CS_CTL_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.setBit<CS_CTL_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_CTL_MISC_GPU1_BAR_RESERVED]

//>> CLEAR_[CS_CTL_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_CTL_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return o_data.clearBit<CS_CTL_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_CTL_MISC_GPU1_BAR_RESERVED]

//>> GET_[CS_CTL_MISC_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_CS_CTL_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.extractToRight<CS_CTL_MISC_GPU1_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_RESERVED]

//>> GET_[CS_CTL_MISC_GPU1_BAR_RESERVED]
static inline bool GET_CS_CTL_MISC_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_CTL_MISC_GPU1_BAR));
#endif
    return i_data.getBit<CS_CTL_MISC_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_CTL_MISC_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_CTL_MISC_GPU1_BAR_RESERVED]

//>> PREP_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_TOPOLOGY_TABLE0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM1_SNP_MISC_TOPOLOGY_TABLE0;
#endif
    return fapi2::getScom(i_target, CS_SM1_SNP_MISC_TOPOLOGY_TABLE0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0]

//>> PUT_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return fapi2::putScom(i_target, CS_SM1_SNP_MISC_TOPOLOGY_TABLE0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0]


//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_ABLE_0_7]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY0]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY1]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY2]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY3]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY4]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY5]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY6]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>> SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& SET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return o_data.insertFromRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>> GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7]
static inline fapi2::buffer<uint64_t>& GET_CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM1_SNP_MISC_TOPOLOGY_TABLE0));
#endif
    return i_data.extractToRight<CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7,
           CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM1_SNP_MISC_TOPOLOGY_TABLE0_TRY7]

//>> PREP_[CS_SM3_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM3_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM3_SNP_MISC_NDT0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM3_SNP_MISC_NDT0_BAR]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM3_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM3_SNP_MISC_NDT0_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM3_SNP_MISC_NDT0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR]

//>> PUT_[CS_SM3_SNP_MISC_NDT0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM3_SNP_MISC_NDT0_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM3_SNP_MISC_NDT0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM3_SNP_MISC_NDT0_BAR]


//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> CLEAR_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]
static inline bool GET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> CLEAR_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]
static inline bool GET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> CLEAR_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]
static inline bool GET_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR,
           CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_ADDR]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> CLEAR_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]
static inline bool GET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_POISON]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2,
           CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_NDT0_RESERVED2]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT0_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE,
           CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT0_BAR_CONFIG_NDT0_BAR_SIZE]

//>> PREP_[CS_SM3_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CS_SM3_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM3_SNP_MISC_NDT1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CS_SM3_SNP_MISC_NDT1_BAR]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CS_SM3_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CS_SM3_SNP_MISC_NDT1_BAR;
#endif
    return fapi2::getScom(i_target, CS_SM3_SNP_MISC_NDT1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR]

//>> PUT_[CS_SM3_SNP_MISC_NDT1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CS_SM3_SNP_MISC_NDT1_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return fapi2::putScom(i_target, CS_SM3_SNP_MISC_NDT1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CS_SM3_SNP_MISC_NDT1_BAR]


//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> CLEAR_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]
static inline bool GET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ENABLE]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> CLEAR_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]
static inline bool GET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SECURE_A12]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> CLEAR_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]
static inline bool GET_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED1]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR,
           CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_ADDR]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.setBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> CLEAR_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.clearBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]
static inline bool GET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.getBit<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_POISON]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2,
           CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_NDT1_RESERVED2]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>> SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return o_data.insertFromRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>> GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]
static inline fapi2::buffer<uint64_t>& GET_CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CS_SM3_SNP_MISC_NDT1_BAR));
#endif
    return i_data.extractToRight<CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE,
           CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CS_SM3_SNP_MISC_NDT1_BAR_CONFIG_NDT1_BAR_SIZE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
