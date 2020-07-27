/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00000.H $          */
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

#ifndef __OMI_REG00000_H_
#define __OMI_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[ERROR_HOLD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ERROR_HOLD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_HOLD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ERROR_HOLD]

//>> GET_[ERROR_HOLD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ERROR_HOLD(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_HOLD;
#endif
    return fapi2::getScom(i_target, ERROR_HOLD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ERROR_HOLD]

//>> PUT_[ERROR_HOLD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ERROR_HOLD(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return fapi2::putScom(i_target, ERROR_HOLD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ERROR_HOLD]


//>> SET_[ERROR_HOLD_47]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_47]

//>> SET_[ERROR_HOLD_47]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_47]

//>> SET_[ERROR_HOLD_47]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_47]

//>> CLEAR_[ERROR_HOLD_47]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_47]

//>> GET_[ERROR_HOLD_47]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_47]

//>> GET_[ERROR_HOLD_47]
static inline bool GET_ERROR_HOLD_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_47]

//>> SET_[ERROR_HOLD_46]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_46]

//>> SET_[ERROR_HOLD_46]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_46]

//>> SET_[ERROR_HOLD_46]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_46]

//>> CLEAR_[ERROR_HOLD_46]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_46]

//>> GET_[ERROR_HOLD_46]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_46]

//>> GET_[ERROR_HOLD_46]
static inline bool GET_ERROR_HOLD_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_46]

//>> SET_[ERROR_HOLD_45]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_45]

//>> SET_[ERROR_HOLD_45]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_45]

//>> SET_[ERROR_HOLD_45]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_45]

//>> CLEAR_[ERROR_HOLD_45]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_45]

//>> GET_[ERROR_HOLD_45]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_45]

//>> GET_[ERROR_HOLD_45]
static inline bool GET_ERROR_HOLD_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_45]

//>> SET_[ERROR_HOLD_44]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_44]

//>> SET_[ERROR_HOLD_44]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_44]

//>> SET_[ERROR_HOLD_44]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_44]

//>> CLEAR_[ERROR_HOLD_44]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_44]

//>> GET_[ERROR_HOLD_44]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_44]

//>> GET_[ERROR_HOLD_44]
static inline bool GET_ERROR_HOLD_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_44]

//>> SET_[ERROR_HOLD_43]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_43]

//>> SET_[ERROR_HOLD_43]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_43]

//>> SET_[ERROR_HOLD_43]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_43]

//>> CLEAR_[ERROR_HOLD_43]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_43]

//>> GET_[ERROR_HOLD_43]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_43]

//>> GET_[ERROR_HOLD_43]
static inline bool GET_ERROR_HOLD_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_43]

//>> SET_[ERROR_HOLD_42]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_42]

//>> SET_[ERROR_HOLD_42]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_42]

//>> SET_[ERROR_HOLD_42]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_42]

//>> CLEAR_[ERROR_HOLD_42]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_42]

//>> GET_[ERROR_HOLD_42]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_42]

//>> GET_[ERROR_HOLD_42]
static inline bool GET_ERROR_HOLD_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_42]

//>> SET_[ERROR_HOLD_41]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_41]

//>> SET_[ERROR_HOLD_41]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_41]

//>> SET_[ERROR_HOLD_41]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_41]

//>> CLEAR_[ERROR_HOLD_41]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_41]

//>> GET_[ERROR_HOLD_41]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_41]

//>> GET_[ERROR_HOLD_41]
static inline bool GET_ERROR_HOLD_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_41]

//>> SET_[ERROR_HOLD_40]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_40]

//>> SET_[ERROR_HOLD_40]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_40]

//>> SET_[ERROR_HOLD_40]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_40]

//>> CLEAR_[ERROR_HOLD_40]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_40]

//>> GET_[ERROR_HOLD_40]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_40]

//>> GET_[ERROR_HOLD_40]
static inline bool GET_ERROR_HOLD_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_40]

//>> SET_[ERROR_HOLD_39]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_39]

//>> SET_[ERROR_HOLD_39]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_39]

//>> SET_[ERROR_HOLD_39]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_39]

//>> CLEAR_[ERROR_HOLD_39]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_39]

//>> GET_[ERROR_HOLD_39]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_39]

//>> GET_[ERROR_HOLD_39]
static inline bool GET_ERROR_HOLD_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_39]

//>> SET_[ERROR_HOLD_38]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_38]

//>> SET_[ERROR_HOLD_38]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_38]

//>> SET_[ERROR_HOLD_38]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_38]

//>> CLEAR_[ERROR_HOLD_38]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_38]

//>> GET_[ERROR_HOLD_38]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_38]

//>> GET_[ERROR_HOLD_38]
static inline bool GET_ERROR_HOLD_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_38]

//>> SET_[ERROR_HOLD_37]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_37]

//>> SET_[ERROR_HOLD_37]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_37]

//>> SET_[ERROR_HOLD_37]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_37]

//>> CLEAR_[ERROR_HOLD_37]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_37]

//>> GET_[ERROR_HOLD_37]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_37]

//>> GET_[ERROR_HOLD_37]
static inline bool GET_ERROR_HOLD_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_37]

//>> SET_[ERROR_HOLD_36]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_36]

//>> SET_[ERROR_HOLD_36]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_36]

//>> SET_[ERROR_HOLD_36]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_36]

//>> CLEAR_[ERROR_HOLD_36]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_36]

//>> GET_[ERROR_HOLD_36]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_36]

//>> GET_[ERROR_HOLD_36]
static inline bool GET_ERROR_HOLD_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_36]

//>> SET_[ERROR_HOLD_35]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_35]

//>> SET_[ERROR_HOLD_35]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_35]

//>> SET_[ERROR_HOLD_35]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_35]

//>> CLEAR_[ERROR_HOLD_35]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_35]

//>> GET_[ERROR_HOLD_35]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_35]

//>> GET_[ERROR_HOLD_35]
static inline bool GET_ERROR_HOLD_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_35]

//>> SET_[ERROR_HOLD_34]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_34]

//>> SET_[ERROR_HOLD_34]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_34]

//>> SET_[ERROR_HOLD_34]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_34]

//>> CLEAR_[ERROR_HOLD_34]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_34]

//>> GET_[ERROR_HOLD_34]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_34]

//>> GET_[ERROR_HOLD_34]
static inline bool GET_ERROR_HOLD_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_34]

//>> SET_[ERROR_HOLD_33]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_33]

//>> SET_[ERROR_HOLD_33]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_33]

//>> SET_[ERROR_HOLD_33]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_33]

//>> CLEAR_[ERROR_HOLD_33]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_33]

//>> GET_[ERROR_HOLD_33]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_33]

//>> GET_[ERROR_HOLD_33]
static inline bool GET_ERROR_HOLD_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_33]

//>> SET_[ERROR_HOLD_32]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_32]

//>> SET_[ERROR_HOLD_32]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_32]

//>> SET_[ERROR_HOLD_32]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_32]

//>> CLEAR_[ERROR_HOLD_32]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_32]

//>> GET_[ERROR_HOLD_32]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_32]

//>> GET_[ERROR_HOLD_32]
static inline bool GET_ERROR_HOLD_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_32]

//>> SET_[ERROR_HOLD_31]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_31]

//>> SET_[ERROR_HOLD_31]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_31]

//>> SET_[ERROR_HOLD_31]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_31]

//>> CLEAR_[ERROR_HOLD_31]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_31]

//>> GET_[ERROR_HOLD_31]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_31]

//>> GET_[ERROR_HOLD_31]
static inline bool GET_ERROR_HOLD_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_31]

//>> SET_[ERROR_HOLD_30]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_30]

//>> SET_[ERROR_HOLD_30]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_30]

//>> SET_[ERROR_HOLD_30]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_30]

//>> CLEAR_[ERROR_HOLD_30]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_30]

//>> GET_[ERROR_HOLD_30]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_30]

//>> GET_[ERROR_HOLD_30]
static inline bool GET_ERROR_HOLD_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_30]

//>> SET_[ERROR_HOLD_29]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_29]

//>> SET_[ERROR_HOLD_29]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_29]

//>> SET_[ERROR_HOLD_29]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_29]

//>> CLEAR_[ERROR_HOLD_29]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_29]

//>> GET_[ERROR_HOLD_29]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_29]

//>> GET_[ERROR_HOLD_29]
static inline bool GET_ERROR_HOLD_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_29]

//>> SET_[ERROR_HOLD_28]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_28]

//>> SET_[ERROR_HOLD_28]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_28]

//>> SET_[ERROR_HOLD_28]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_28]

//>> CLEAR_[ERROR_HOLD_28]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_28]

//>> GET_[ERROR_HOLD_28]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_28]

//>> GET_[ERROR_HOLD_28]
static inline bool GET_ERROR_HOLD_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_28]

//>> SET_[ERROR_HOLD_27]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_27]

//>> SET_[ERROR_HOLD_27]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_27]

//>> SET_[ERROR_HOLD_27]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_27]

//>> CLEAR_[ERROR_HOLD_27]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_27]

//>> GET_[ERROR_HOLD_27]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_27]

//>> GET_[ERROR_HOLD_27]
static inline bool GET_ERROR_HOLD_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_27]

//>> SET_[ERROR_HOLD_26]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_26]

//>> SET_[ERROR_HOLD_26]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_26]

//>> SET_[ERROR_HOLD_26]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_26]

//>> CLEAR_[ERROR_HOLD_26]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_26]

//>> GET_[ERROR_HOLD_26]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_26]

//>> GET_[ERROR_HOLD_26]
static inline bool GET_ERROR_HOLD_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_26]

//>> SET_[ERROR_HOLD_25]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_25]

//>> SET_[ERROR_HOLD_25]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_25]

//>> SET_[ERROR_HOLD_25]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_25]

//>> CLEAR_[ERROR_HOLD_25]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_25]

//>> GET_[ERROR_HOLD_25]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_25]

//>> GET_[ERROR_HOLD_25]
static inline bool GET_ERROR_HOLD_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_25]

//>> SET_[ERROR_HOLD_24]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_24]

//>> SET_[ERROR_HOLD_24]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_24]

//>> SET_[ERROR_HOLD_24]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_24]

//>> CLEAR_[ERROR_HOLD_24]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_24]

//>> GET_[ERROR_HOLD_24]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_24]

//>> GET_[ERROR_HOLD_24]
static inline bool GET_ERROR_HOLD_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_24]

//>> SET_[ERROR_HOLD_23]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_23]

//>> SET_[ERROR_HOLD_23]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_23]

//>> SET_[ERROR_HOLD_23]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_23]

//>> CLEAR_[ERROR_HOLD_23]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_23]

//>> GET_[ERROR_HOLD_23]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_23]

//>> GET_[ERROR_HOLD_23]
static inline bool GET_ERROR_HOLD_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_23]

//>> SET_[ERROR_HOLD_22]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_22]

//>> SET_[ERROR_HOLD_22]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_22]

//>> SET_[ERROR_HOLD_22]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_22]

//>> CLEAR_[ERROR_HOLD_22]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_22]

//>> GET_[ERROR_HOLD_22]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_22]

//>> GET_[ERROR_HOLD_22]
static inline bool GET_ERROR_HOLD_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_22]

//>> SET_[ERROR_HOLD_21]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_21]

//>> SET_[ERROR_HOLD_21]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_21]

//>> SET_[ERROR_HOLD_21]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_21]

//>> CLEAR_[ERROR_HOLD_21]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_21]

//>> GET_[ERROR_HOLD_21]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_21]

//>> GET_[ERROR_HOLD_21]
static inline bool GET_ERROR_HOLD_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_21]

//>> SET_[ERROR_HOLD_20]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_20]

//>> SET_[ERROR_HOLD_20]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_20]

//>> SET_[ERROR_HOLD_20]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_20]

//>> CLEAR_[ERROR_HOLD_20]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_20]

//>> GET_[ERROR_HOLD_20]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_20]

//>> GET_[ERROR_HOLD_20]
static inline bool GET_ERROR_HOLD_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_20]

//>> SET_[ERROR_HOLD_19]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_19]

//>> SET_[ERROR_HOLD_19]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_19]

//>> SET_[ERROR_HOLD_19]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_19]

//>> CLEAR_[ERROR_HOLD_19]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_19]

//>> GET_[ERROR_HOLD_19]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_19]

//>> GET_[ERROR_HOLD_19]
static inline bool GET_ERROR_HOLD_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_19]

//>> SET_[ERROR_HOLD_18]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_18]

//>> SET_[ERROR_HOLD_18]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_18]

//>> SET_[ERROR_HOLD_18]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_18]

//>> CLEAR_[ERROR_HOLD_18]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_18]

//>> GET_[ERROR_HOLD_18]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_18]

//>> GET_[ERROR_HOLD_18]
static inline bool GET_ERROR_HOLD_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_18]

//>> SET_[ERROR_HOLD_17]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_17]

//>> SET_[ERROR_HOLD_17]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_17]

//>> SET_[ERROR_HOLD_17]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_17]

//>> CLEAR_[ERROR_HOLD_17]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_17]

//>> GET_[ERROR_HOLD_17]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_17]

//>> GET_[ERROR_HOLD_17]
static inline bool GET_ERROR_HOLD_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_17]

//>> SET_[ERROR_HOLD_16]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_16]

//>> SET_[ERROR_HOLD_16]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_16]

//>> SET_[ERROR_HOLD_16]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_16]

//>> CLEAR_[ERROR_HOLD_16]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_16]

//>> GET_[ERROR_HOLD_16]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_16]

//>> GET_[ERROR_HOLD_16]
static inline bool GET_ERROR_HOLD_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_16]

//>> SET_[ERROR_HOLD_15]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_15]

//>> SET_[ERROR_HOLD_15]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_15]

//>> SET_[ERROR_HOLD_15]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_15]

//>> CLEAR_[ERROR_HOLD_15]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_15]

//>> GET_[ERROR_HOLD_15]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_15]

//>> GET_[ERROR_HOLD_15]
static inline bool GET_ERROR_HOLD_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_15]

//>> SET_[ERROR_HOLD_14]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_14]

//>> SET_[ERROR_HOLD_14]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_14]

//>> SET_[ERROR_HOLD_14]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_14]

//>> CLEAR_[ERROR_HOLD_14]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_14]

//>> GET_[ERROR_HOLD_14]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_14]

//>> GET_[ERROR_HOLD_14]
static inline bool GET_ERROR_HOLD_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_14]

//>> SET_[ERROR_HOLD_13]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_13]

//>> SET_[ERROR_HOLD_13]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_13]

//>> SET_[ERROR_HOLD_13]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_13]

//>> CLEAR_[ERROR_HOLD_13]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_13]

//>> GET_[ERROR_HOLD_13]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_13]

//>> GET_[ERROR_HOLD_13]
static inline bool GET_ERROR_HOLD_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_13]

//>> SET_[ERROR_HOLD_12]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_12]

//>> SET_[ERROR_HOLD_12]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_12]

//>> SET_[ERROR_HOLD_12]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_12]

//>> CLEAR_[ERROR_HOLD_12]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_12]

//>> GET_[ERROR_HOLD_12]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_12]

//>> GET_[ERROR_HOLD_12]
static inline bool GET_ERROR_HOLD_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_12]

//>> SET_[ERROR_HOLD_11]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_11]

//>> SET_[ERROR_HOLD_11]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_11]

//>> SET_[ERROR_HOLD_11]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_11]

//>> CLEAR_[ERROR_HOLD_11]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_11]

//>> GET_[ERROR_HOLD_11]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_11]

//>> GET_[ERROR_HOLD_11]
static inline bool GET_ERROR_HOLD_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_11]

//>> SET_[ERROR_HOLD_10]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_10]

//>> SET_[ERROR_HOLD_10]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_10]

//>> SET_[ERROR_HOLD_10]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_10]

//>> CLEAR_[ERROR_HOLD_10]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_10]

//>> GET_[ERROR_HOLD_10]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_10]

//>> GET_[ERROR_HOLD_10]
static inline bool GET_ERROR_HOLD_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_10]

//>> SET_[ERROR_HOLD_09]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_09]

//>> SET_[ERROR_HOLD_09]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_09]

//>> SET_[ERROR_HOLD_09]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_09]

//>> CLEAR_[ERROR_HOLD_09]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_09]

//>> GET_[ERROR_HOLD_09]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_09]

//>> GET_[ERROR_HOLD_09]
static inline bool GET_ERROR_HOLD_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_09]

//>> SET_[ERROR_HOLD_08]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_08]

//>> SET_[ERROR_HOLD_08]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_08]

//>> SET_[ERROR_HOLD_08]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_08]

//>> CLEAR_[ERROR_HOLD_08]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_08]

//>> GET_[ERROR_HOLD_08]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_08]

//>> GET_[ERROR_HOLD_08]
static inline bool GET_ERROR_HOLD_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_08]

//>> SET_[ERROR_HOLD_07]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_07]

//>> SET_[ERROR_HOLD_07]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_07]

//>> SET_[ERROR_HOLD_07]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_07]

//>> CLEAR_[ERROR_HOLD_07]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_07]

//>> GET_[ERROR_HOLD_07]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_07]

//>> GET_[ERROR_HOLD_07]
static inline bool GET_ERROR_HOLD_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_07]

//>> SET_[ERROR_HOLD_06]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_06]

//>> SET_[ERROR_HOLD_06]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_06]

//>> SET_[ERROR_HOLD_06]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_06]

//>> CLEAR_[ERROR_HOLD_06]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_06]

//>> GET_[ERROR_HOLD_06]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_06]

//>> GET_[ERROR_HOLD_06]
static inline bool GET_ERROR_HOLD_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_06]

//>> SET_[ERROR_HOLD_05]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_05]

//>> SET_[ERROR_HOLD_05]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_05]

//>> SET_[ERROR_HOLD_05]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_05]

//>> CLEAR_[ERROR_HOLD_05]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_05]

//>> GET_[ERROR_HOLD_05]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_05]

//>> GET_[ERROR_HOLD_05]
static inline bool GET_ERROR_HOLD_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_05]

//>> SET_[ERROR_HOLD_04]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_04]

//>> SET_[ERROR_HOLD_04]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_04]

//>> SET_[ERROR_HOLD_04]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_04]

//>> CLEAR_[ERROR_HOLD_04]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_04]

//>> GET_[ERROR_HOLD_04]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_04]

//>> GET_[ERROR_HOLD_04]
static inline bool GET_ERROR_HOLD_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_04]

//>> SET_[ERROR_HOLD_03]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_03]

//>> SET_[ERROR_HOLD_03]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_03]

//>> SET_[ERROR_HOLD_03]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_03]

//>> CLEAR_[ERROR_HOLD_03]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_03]

//>> GET_[ERROR_HOLD_03]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_03]

//>> GET_[ERROR_HOLD_03]
static inline bool GET_ERROR_HOLD_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_03]

//>> SET_[ERROR_HOLD_02]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_02]

//>> SET_[ERROR_HOLD_02]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_02]

//>> SET_[ERROR_HOLD_02]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_02]

//>> CLEAR_[ERROR_HOLD_02]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_02]

//>> GET_[ERROR_HOLD_02]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_02]

//>> GET_[ERROR_HOLD_02]
static inline bool GET_ERROR_HOLD_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_02]

//>> SET_[ERROR_HOLD_01]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_01]

//>> SET_[ERROR_HOLD_01]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_01]

//>> SET_[ERROR_HOLD_01]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_01]

//>> CLEAR_[ERROR_HOLD_01]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_01]

//>> GET_[ERROR_HOLD_01]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_01]

//>> GET_[ERROR_HOLD_01]
static inline bool GET_ERROR_HOLD_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_01]

//>> SET_[ERROR_HOLD_00]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_HOLD_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_00]

//>> SET_[ERROR_HOLD_00]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.insertFromRight<ERROR_HOLD_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_HOLD_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_00]

//>> SET_[ERROR_HOLD_00]
static inline fapi2::buffer<uint64_t>& SET_ERROR_HOLD_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.setBit<ERROR_HOLD_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access ERROR_HOLD_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_HOLD_00]

//>> CLEAR_[ERROR_HOLD_00]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_HOLD_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return o_data.clearBit<ERROR_HOLD_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access ERROR_HOLD_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_HOLD_00]

//>> GET_[ERROR_HOLD_00]
static inline fapi2::buffer<uint64_t>& GET_ERROR_HOLD_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.extractToRight<ERROR_HOLD_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_HOLD_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_00]

//>> GET_[ERROR_HOLD_00]
static inline bool GET_ERROR_HOLD_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_HOLD));
#endif
    return i_data.getBit<ERROR_HOLD_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access ERROR_HOLD_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_HOLD_00]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
