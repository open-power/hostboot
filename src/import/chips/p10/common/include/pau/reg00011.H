/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00011.H $          */
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

#ifndef __PAU_REG00011_H_
#define __PAU_REG00011_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> PREP_[XSL_MAIN_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_GPU0_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_GPU0_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSL_MAIN_GPU0_BAR]

//>> GET_[XSL_MAIN_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_GPU0_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_GPU0_BAR;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_GPU0_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR]

//>> PUT_[XSL_MAIN_GPU0_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_GPU0_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_GPU0_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSL_MAIN_GPU0_BAR]


//>> SET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> GET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> GET_[XSL_MAIN_GPU0_BAR_ENABLE]
static inline bool GET_XSL_MAIN_GPU0_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_ADDR_MASK,
           XSL_MAIN_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]

//>> SET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_ADDR_MASK,
           XSL_MAIN_GPU0_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]

//>> GET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_ADDR_MASK,
           XSL_MAIN_GPU0_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_ADDR_MASK]

//>> SET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_SL_MODE]
static inline bool GET_XSL_MAIN_GPU0_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> GET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> GET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]
static inline bool GET_XSL_MAIN_GPU0_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_4T_SELECT,
           XSL_MAIN_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_SELECT]

//>> SET_[XSL_MAIN_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_4T_SELECT,
           XSL_MAIN_GPU0_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_4T_SELECT]

//>> GET_[XSL_MAIN_GPU0_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_4T_SELECT,
           XSL_MAIN_GPU0_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_4T_SELECT]

//>> SET_[XSL_MAIN_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_MODE,
           XSL_MAIN_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_MODE,
           XSL_MAIN_GPU0_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_MODE,
           XSL_MAIN_GPU0_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> GET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> GET_[XSL_MAIN_GPU0_BAR_GRANULE]
static inline bool GET_XSL_MAIN_GPU0_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_POISON]

//>> SET_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_POISON]

//>> SET_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_POISON]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_POISON]

//>> GET_[XSL_MAIN_GPU0_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_POISON]

//>> GET_[XSL_MAIN_GPU0_BAR_POISON]
static inline bool GET_XSL_MAIN_GPU0_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_POISON]

//>> SET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_M2MODE]
static inline bool GET_XSL_MAIN_GPU0_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]
static inline bool GET_XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> GET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> GET_[XSL_MAIN_GPU0_BAR_SECURE_A12]
static inline bool GET_XSL_MAIN_GPU0_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> GET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]
static inline bool GET_XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> GET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]
static inline bool GET_XSL_MAIN_GPU0_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> SET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU0_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> SET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> CLEAR_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> GET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU0_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> GET_[XSL_MAIN_GPU0_BAR_RESERVED]
static inline bool GET_XSL_MAIN_GPU0_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU0_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU0_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU0_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU0_BAR_RESERVED]

//>> PREP_[XSL_MAIN_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_GPU1_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_GPU1_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSL_MAIN_GPU1_BAR]

//>> GET_[XSL_MAIN_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_GPU1_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_GPU1_BAR;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_GPU1_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR]

//>> PUT_[XSL_MAIN_GPU1_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_GPU1_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_GPU1_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSL_MAIN_GPU1_BAR]


//>> SET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> GET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> GET_[XSL_MAIN_GPU1_BAR_ENABLE]
static inline bool GET_XSL_MAIN_GPU1_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_ENABLE]

//>> SET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_ADDR_MASK,
           XSL_MAIN_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]

//>> SET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_ADDR_MASK,
           XSL_MAIN_GPU1_BAR_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]

//>> GET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_ADDR_MASK,
           XSL_MAIN_GPU1_BAR_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_ADDR_MASK]

//>> SET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_SL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_SL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_SL_MODE]
static inline bool GET_XSL_MAIN_GPU1_BAR_SL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_SL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_SL_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_4T_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> GET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_4T_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> GET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]
static inline bool GET_XSL_MAIN_GPU1_BAR_4T_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_4T_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_4T_LIMIT]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_4T_SELECT,
           XSL_MAIN_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_SELECT]

//>> SET_[XSL_MAIN_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_4T_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_4T_SELECT,
           XSL_MAIN_GPU1_BAR_4T_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_4T_SELECT]

//>> GET_[XSL_MAIN_GPU1_BAR_4T_SELECT]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_4T_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_4T_SELECT,
           XSL_MAIN_GPU1_BAR_4T_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_4T_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_4T_SELECT]

//>> SET_[XSL_MAIN_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_MODE,
           XSL_MAIN_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_MODE,
           XSL_MAIN_GPU1_BAR_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_MODE,
           XSL_MAIN_GPU1_BAR_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_GRANULE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_GRANULE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> GET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_GRANULE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> GET_[XSL_MAIN_GPU1_BAR_GRANULE]
static inline bool GET_XSL_MAIN_GPU1_BAR_GRANULE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_GRANULE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_GRANULE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_GRANULE]

//>> SET_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_POISON]

//>> SET_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_POISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_POISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_POISON]

//>> SET_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_POISON]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_POISON]

//>> GET_[XSL_MAIN_GPU1_BAR_POISON]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_POISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_POISON]

//>> GET_[XSL_MAIN_GPU1_BAR_POISON]
static inline bool GET_XSL_MAIN_GPU1_BAR_POISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_POISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_POISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_POISON]

//>> SET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_M2MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_M2MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_M2MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_M2MODE]
static inline bool GET_XSL_MAIN_GPU1_BAR_M2MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_M2MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_M2MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_M2MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]
static inline bool GET_XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SECURE_A12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_SECURE_A12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> GET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_SECURE_A12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> GET_[XSL_MAIN_GPU1_BAR_SECURE_A12]
static inline bool GET_XSL_MAIN_GPU1_BAR_SECURE_A12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_SECURE_A12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_SECURE_A12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_SECURE_A12]

//>> SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> GET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]
static inline bool GET_XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP]

//>> SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> GET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]
static inline bool GET_XSL_MAIN_GPU1_BAR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_EXTENDED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_EXTENDED_MODE]

//>> SET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> SET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.insertFromRight<XSL_MAIN_GPU1_BAR_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> SET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.setBit<XSL_MAIN_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> CLEAR_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return o_data.clearBit<XSL_MAIN_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> GET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.extractToRight<XSL_MAIN_GPU1_BAR_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>> GET_[XSL_MAIN_GPU1_BAR_RESERVED]
static inline bool GET_XSL_MAIN_GPU1_BAR_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_GPU1_BAR));
#endif
    return i_data.getBit<XSL_MAIN_GPU1_BAR_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pau Invalid dial access XSL_MAIN_GPU1_BAR_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSL_MAIN_GPU1_BAR_RESERVED]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
