/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00015.H $         */
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

#ifndef __PERV_REG00015_H_
#define __PERV_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG38]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG38(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG38;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG38]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG38]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG38(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG38;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG38, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG38]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG38]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG38(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG38));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG38, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG38]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG38));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38,
           SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG38));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38,
           SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG38));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38,
           SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG38_REGISTER38]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG46]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG46(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG46;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG46]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG46]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG46(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG46;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG46, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG46]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG46]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG46(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG46));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG46, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG46]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG46));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46,
           SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG46));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46,
           SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG46));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46,
           SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG46_REGISTER46]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG59]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG59(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG59;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG59]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG59]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG59(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG59;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG59, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG59]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG59]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG59(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG59));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG59, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG59]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG59));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59,
           SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG59));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59,
           SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG59));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59,
           SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG59_REGISTER59]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG71]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG71(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG71;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG71]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG71]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG71(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG71;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG71, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG71]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG71]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG71(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG71));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG71, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG71]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG71));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71,
           SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG71));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71,
           SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG71));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71,
           SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG71_REGISTER71]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG84]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG84(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG84;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG84]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG84]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG84(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG84;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG84, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG84]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG84]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG84(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG84));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG84, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG84]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG84));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84,
           SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG84));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84,
           SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG84));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84,
           SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG84_REGISTER84]

//>> PREP_[SPATTN_UNMASKED]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SPATTN_UNMASKED(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_UNMASKED;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SPATTN_UNMASKED]

//>> GET_[SPATTN_UNMASKED]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SPATTN_UNMASKED(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_UNMASKED;
#endif
    return fapi2::getScom(i_target, SPATTN_UNMASKED, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SPATTN_UNMASKED]

//>> PUT_[SPATTN_UNMASKED]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SPATTN_UNMASKED(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SPATTN_UNMASKED));
#endif
    return fapi2::putScom(i_target, SPATTN_UNMASKED, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SPATTN_UNMASKED]


//>> SET_[SPATTN_UNMASKED_IN]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_UNMASKED_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_UNMASKED));
#endif
    return o_data.insertFromRight<SPATTN_UNMASKED_IN,
           SPATTN_UNMASKED_IN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_UNMASKED_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_UNMASKED_IN]

//>> SET_[SPATTN_UNMASKED_IN]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_UNMASKED_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_UNMASKED));
#endif
    return o_data.insertFromRight<SPATTN_UNMASKED_IN,
           SPATTN_UNMASKED_IN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_UNMASKED_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_UNMASKED_IN]

//>> GET_[SPATTN_UNMASKED_IN]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_UNMASKED_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_UNMASKED));
#endif
    return i_data.extractToRight<SPATTN_UNMASKED_IN,
           SPATTN_UNMASKED_IN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_UNMASKED_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_UNMASKED_IN]

//>> PREP_[SYNC_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SYNC_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SYNC_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SYNC_CONFIG]

//>> GET_[SYNC_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SYNC_CONFIG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SYNC_CONFIG;
#endif
    return fapi2::getScom(i_target, SYNC_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SYNC_CONFIG]

//>> PUT_[SYNC_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SYNC_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return fapi2::putScom(i_target, SYNC_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SYNC_CONFIG]


//>> SET_[SYNC_CONFIG_SYNC_PULSE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_SYNC_PULSE_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_SYNC_PULSE_DELAY,
           SYNC_CONFIG_SYNC_PULSE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_SYNC_PULSE_DELAY]

//>> SET_[SYNC_CONFIG_SYNC_PULSE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_SYNC_PULSE_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_SYNC_PULSE_DELAY,
           SYNC_CONFIG_SYNC_PULSE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_SYNC_PULSE_DELAY]

//>> GET_[SYNC_CONFIG_SYNC_PULSE_DELAY]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_SYNC_PULSE_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_SYNC_PULSE_DELAY,
           SYNC_CONFIG_SYNC_PULSE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_SYNC_PULSE_DELAY]

//>> SET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]

//>> SET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]

//>> SET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]

//>> CLEAR_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]

//>> GET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]

//>> GET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]
static inline bool GET_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS]

//>> SET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_SYNC_PULSE_INPUT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]

//>> SET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_SYNC_PULSE_INPUT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]

//>> SET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_SYNC_PULSE_INPUT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]

//>> CLEAR_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_SYNC_PULSE_INPUT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]

//>> GET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_SYNC_PULSE_INPUT_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]

//>> GET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]
static inline bool GET_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_SYNC_PULSE_INPUT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_SYNC_PULSE_INPUT_SEL]

//>> SET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_USE_SYNC_FOR_SCAN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_USE_SYNC_FOR_SCAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]

//>> SET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_USE_SYNC_FOR_SCAN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_USE_SYNC_FOR_SCAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]

//>> SET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_USE_SYNC_FOR_SCAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_USE_SYNC_FOR_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]

//>> CLEAR_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_USE_SYNC_FOR_SCAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_USE_SYNC_FOR_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]

//>> GET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_USE_SYNC_FOR_SCAN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_USE_SYNC_FOR_SCAN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]

//>> GET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]
static inline bool GET_SYNC_CONFIG_USE_SYNC_FOR_SCAN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_USE_SYNC_FOR_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_USE_SYNC_FOR_SCAN]

//>> SET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]

//>> SET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]

//>> SET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]

//>> CLEAR_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]

//>> GET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]

//>> GET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]
static inline bool GET_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED]

//>> SET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]

//>> SET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]

//>> SET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]

//>> CLEAR_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]

//>> GET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]

//>> GET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]
static inline bool GET_SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD]

//>> SET_[SYNC_CONFIG_DISABLE_PCB_ITR]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_DISABLE_PCB_ITR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_DISABLE_PCB_ITR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_DISABLE_PCB_ITR]

//>> SET_[SYNC_CONFIG_DISABLE_PCB_ITR]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_DISABLE_PCB_ITR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_DISABLE_PCB_ITR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_DISABLE_PCB_ITR]

//>> SET_[SYNC_CONFIG_DISABLE_PCB_ITR]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_DISABLE_PCB_ITR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_DISABLE_PCB_ITR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_DISABLE_PCB_ITR]

//>> CLEAR_[SYNC_CONFIG_DISABLE_PCB_ITR]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_DISABLE_PCB_ITR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_DISABLE_PCB_ITR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_DISABLE_PCB_ITR]

//>> GET_[SYNC_CONFIG_DISABLE_PCB_ITR]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_DISABLE_PCB_ITR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_DISABLE_PCB_ITR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_DISABLE_PCB_ITR]

//>> GET_[SYNC_CONFIG_DISABLE_PCB_ITR]
static inline bool GET_SYNC_CONFIG_DISABLE_PCB_ITR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_DISABLE_PCB_ITR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_DISABLE_PCB_ITR]

//>> SET_[SYNC_CONFIG_CONT_SCAN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CONT_SCAN_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_CONT_SCAN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CONT_SCAN_DISABLE]

//>> SET_[SYNC_CONFIG_CONT_SCAN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CONT_SCAN_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_CONT_SCAN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CONT_SCAN_DISABLE]

//>> SET_[SYNC_CONFIG_CONT_SCAN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CONT_SCAN_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_CONT_SCAN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CONT_SCAN_DISABLE]

//>> CLEAR_[SYNC_CONFIG_CONT_SCAN_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_CONT_SCAN_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_CONT_SCAN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_CONT_SCAN_DISABLE]

//>> GET_[SYNC_CONFIG_CONT_SCAN_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_CONT_SCAN_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_CONT_SCAN_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_CONT_SCAN_DISABLE]

//>> GET_[SYNC_CONFIG_CONT_SCAN_DISABLE]
static inline bool GET_SYNC_CONFIG_CONT_SCAN_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_CONT_SCAN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_CONT_SCAN_DISABLE]

//>> SET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_SYNC_PULSE_OUT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_SYNC_PULSE_OUT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]

//>> SET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_SYNC_PULSE_OUT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_SYNC_PULSE_OUT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]

//>> SET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_SYNC_PULSE_OUT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_SYNC_PULSE_OUT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]

//>> CLEAR_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_SYNC_PULSE_OUT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_SYNC_PULSE_OUT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]

//>> GET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_SYNC_PULSE_OUT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_SYNC_PULSE_OUT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]

//>> GET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]
static inline bool GET_SYNC_CONFIG_SYNC_PULSE_OUT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_SYNC_PULSE_OUT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_SYNC_PULSE_OUT_DIS]

//>> SET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_REGION_PGOOD_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_REGION_PGOOD_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]

//>> SET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_REGION_PGOOD_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_REGION_PGOOD_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]

//>> SET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_REGION_PGOOD_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_REGION_PGOOD_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]

//>> CLEAR_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_REGION_PGOOD_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_REGION_PGOOD_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]

//>> GET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_REGION_PGOOD_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_REGION_PGOOD_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]

//>> GET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]
static inline bool GET_SYNC_CONFIG_REGION_PGOOD_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_REGION_PGOOD_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_REGION_PGOOD_OVERRIDE]

//>> SET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CONT_SCAN_SHORT_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_CONT_SCAN_SHORT_WAIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]

//>> SET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CONT_SCAN_SHORT_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_CONT_SCAN_SHORT_WAIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]

//>> SET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_CONT_SCAN_SHORT_WAIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_CONT_SCAN_SHORT_WAIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]

//>> CLEAR_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_CONT_SCAN_SHORT_WAIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_CONT_SCAN_SHORT_WAIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]

//>> GET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_CONT_SCAN_SHORT_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_CONT_SCAN_SHORT_WAIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]

//>> GET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]
static inline bool GET_SYNC_CONFIG_CONT_SCAN_SHORT_WAIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_CONT_SCAN_SHORT_WAIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]

//>> SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]

//>> SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]

//>> SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]

//>> CLEAR_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]

//>> GET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]

//>> GET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]
static inline bool GET_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN]

//>> SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE,
           SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE]

//>> SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE]
static inline fapi2::buffer<uint64_t>& SET_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE,
           SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE]

//>> GET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE]
static inline fapi2::buffer<uint64_t>& GET_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE,
           SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE]

//>> PREP_[TOD_CHIP_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_CHIP_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_CHIP_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_CHIP_CTRL_REG]

//>> GET_[TOD_CHIP_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_CHIP_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_CHIP_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_CHIP_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG]

//>> PUT_[TOD_CHIP_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_CHIP_CTRL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_CHIP_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_CHIP_CTRL_REG]


//>> SET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]
static inline bool GET_TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT,
           TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT]

//>> SET_[TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT,
           TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT]

//>> GET_[TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT,
           TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT]

//>> SET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]

//>> SET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]

//>> SET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]

//>> GET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]

//>> GET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]
static inline bool GET_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE]

//>> SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]

//>> SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]

//>> SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]

//>> GET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]

//>> GET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]
static inline bool GET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE]

//>> SET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]
static inline bool GET_TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]
static inline bool GET_TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]

//>> SET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]

//>> SET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]

//>> CLEAR_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]

//>> GET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]

//>> GET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]
static inline bool GET_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM]

//>> SET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]

//>> SET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]

//>> SET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]

//>> CLEAR_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]

//>> GET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]

//>> GET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]
static inline bool GET_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC]

//>> SET_[TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE,
           TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE]

//>> SET_[TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE,
           TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE]

//>> GET_[TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE,
           TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE]

//>> SET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]
static inline bool GET_TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18]

//>> GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23]

//>> GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25]

//>> GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25,
           TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25]

//>> SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]

//>> SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]

//>> SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]

//>> CLEAR_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]

//>> GET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]

//>> GET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]
static inline bool GET_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]

//>> CLEAR_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]

//>> GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]

//>> GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]
static inline bool GET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27]

//>> SET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]
static inline bool GET_TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]

//>> SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]

//>> CLEAR_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]

//>> GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]

//>> GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]
static inline bool GET_TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29]

//>> SET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_XSTOP_GATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_XSTOP_GATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_XSTOP_GATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]

//>> SET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_XSTOP_GATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_XSTOP_GATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_XSTOP_GATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]

//>> SET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_XSTOP_GATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_XSTOP_GATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_XSTOP_GATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_XSTOP_GATE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_XSTOP_GATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_XSTOP_GATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_XSTOP_GATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_XSTOP_GATE]

//>> GET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_XSTOP_GATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_XSTOP_GATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_XSTOP_GATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]

//>> GET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]
static inline bool GET_TOD_CHIP_CTRL_REG_XSTOP_GATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_XSTOP_GATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_XSTOP_GATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_XSTOP_GATE]

//>> SET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]

//>> SET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.setBit<TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]

//>> CLEAR_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return o_data.clearBit<TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]

//>> GET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]
static inline bool GET_TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_CHIP_CTRL_REG));
#endif
    return i_data.getBit<TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE]

//>> PREP_[TOD_ERROR_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_ERROR_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_ERROR_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_ERROR_MASK_REG]

//>> GET_[TOD_ERROR_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_ERROR_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_ERROR_MASK_REG;
#endif
    return fapi2::getScom(i_target, TOD_ERROR_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG]

//>> PUT_[TOD_ERROR_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_ERROR_MASK_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return fapi2::putScom(i_target, TOD_ERROR_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_ERROR_MASK_REG]


//>> SET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PSS_HAM_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PSS_HAM_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PSS_HAM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PSS_HAM_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PSS_HAM_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PSS_HAM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PSS_HAM_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_PSS_HAM_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PSS_HAM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_PSS_HAM_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_PSS_HAM_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PSS_HAM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PSS_HAM_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PSS_HAM_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PSS_HAM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_PSS_HAM_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_PSS_HAM_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PSS_HAM_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PSS_HAM_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>&
CLEAR_TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]

//>> SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]

//>> GET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK]

//>> SET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK,
           TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK,
           TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK,
           TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]

//>> GET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]

//>> CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]
static inline bool GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]

//>> CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]
static inline bool GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]

//>> CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]
static inline bool GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]

//>> CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]
static inline bool GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61]

//>> SET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]

//>> SET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]

//>> SET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]

//>> CLEAR_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]

//>> GET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]

//>> GET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]
static inline bool GET_TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]

//>> SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.setBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]

//>> CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return o_data.clearBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]

//>> GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]
static inline bool GET_TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_MASK_REG));
#endif
    return i_data.getBit<TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63]

//>> PREP_[TOD_ERROR_ROUTING_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_ERROR_ROUTING_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_ERROR_ROUTING_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_ERROR_ROUTING_REG]

//>> GET_[TOD_ERROR_ROUTING_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_ERROR_ROUTING_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_ERROR_ROUTING_REG;
#endif
    return fapi2::getScom(i_target, TOD_ERROR_ROUTING_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG]

//>> PUT_[TOD_ERROR_ROUTING_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_ERROR_ROUTING_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return fapi2::putScom(i_target, TOD_ERROR_ROUTING_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_ERROR_ROUTING_REG]


//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]

//>> SET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]

//>> SET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]

//>> GET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]

//>> GET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]
static inline bool GET_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>&
SET_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>&
SET_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>&
SET_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>&
CLEAR_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>&
GET_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]

//>> SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]

//>> GET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]
static inline bool GET_TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT]

//>> SET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING,
           TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING,
           TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING,
           TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]
static inline bool GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]
static inline bool GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]
static inline bool GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]
static inline bool GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61]

//>> SET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]

//>> GET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]
static inline bool GET_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]

//>> SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.setBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]

//>> CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return o_data.clearBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]

//>> GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]
static inline bool GET_TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_ROUTING_REG));
#endif
    return i_data.getBit<TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63]

//>> PREP_[TOD_I_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_I_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_I_PATH_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_I_PATH_CTRL_REG]

//>> GET_[TOD_I_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_I_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_I_PATH_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_I_PATH_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG]

//>> PUT_[TOD_I_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_I_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_I_PATH_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_I_PATH_CTRL_REG]


//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]

//>> CLEAR_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]
static inline bool GET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]

//>> CLEAR_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]
static inline bool GET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04,
           TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04]

//>> SET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04,
           TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04]

//>> GET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04,
           TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]

//>> CLEAR_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]
static inline bool GET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> CLEAR_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline bool GET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT,
           TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21,
           TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21]

//>> SET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21,
           TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21]

//>> GET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21,
           TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE,
           TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE,
           TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE,
           TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_CPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_CPS,
           TOD_I_PATH_CTRL_REG_I_PATH_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_CPS]

//>> SET_[TOD_I_PATH_CTRL_REG_I_PATH_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_I_PATH_CTRL_REG_I_PATH_CPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_I_PATH_CTRL_REG_I_PATH_CPS,
           TOD_I_PATH_CTRL_REG_I_PATH_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_I_PATH_CTRL_REG_I_PATH_CPS]

//>> GET_[TOD_I_PATH_CTRL_REG_I_PATH_CPS]
static inline fapi2::buffer<uint64_t>& GET_TOD_I_PATH_CTRL_REG_I_PATH_CPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_I_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_I_PATH_CTRL_REG_I_PATH_CPS,
           TOD_I_PATH_CTRL_REG_I_PATH_CPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_I_PATH_CTRL_REG_I_PATH_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_I_PATH_CTRL_REG_I_PATH_CPS]

//>> PREP_[TOD_MOVE_TO_TB_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_MOVE_TO_TB_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_MOVE_TO_TB_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_MOVE_TO_TB_REG]

//>> GET_[TOD_MOVE_TO_TB_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_MOVE_TO_TB_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_MOVE_TO_TB_REG;
#endif
    return fapi2::getScom(i_target, TOD_MOVE_TO_TB_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_MOVE_TO_TB_REG]

//>> PUT_[TOD_MOVE_TO_TB_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_MOVE_TO_TB_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_MOVE_TO_TB_REG));
#endif
    return fapi2::putScom(i_target, TOD_MOVE_TO_TB_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_MOVE_TO_TB_REG]


//>> SET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MOVE_TO_TB_REG));
#endif
    return o_data.insertFromRight<TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]

//>> SET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MOVE_TO_TB_REG));
#endif
    return o_data.insertFromRight<TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]

//>> SET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MOVE_TO_TB_REG));
#endif
    return o_data.setBit<TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]

//>> CLEAR_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MOVE_TO_TB_REG));
#endif
    return o_data.clearBit<TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]

//>> GET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MOVE_TO_TB_REG));
#endif
    return i_data.extractToRight<TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]

//>> GET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]
static inline bool GET_TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MOVE_TO_TB_REG));
#endif
    return i_data.getBit<TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER]

//>> PREP_[TOD_M_PATH_1_STEP_STEER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_M_PATH_1_STEP_STEER_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_M_PATH_1_STEP_STEER_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_M_PATH_1_STEP_STEER_REG]

//>> GET_[TOD_M_PATH_1_STEP_STEER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_M_PATH_1_STEP_STEER_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_M_PATH_1_STEP_STEER_REG;
#endif
    return fapi2::getScom(i_target, TOD_M_PATH_1_STEP_STEER_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_M_PATH_1_STEP_STEER_REG]

//>> PUT_[TOD_M_PATH_1_STEP_STEER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_M_PATH_1_STEP_STEER_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return fapi2::putScom(i_target, TOD_M_PATH_1_STEP_STEER_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_M_PATH_1_STEP_STEER_REG]


//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_1_STEP_STEER_REG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_1_STEP_STEER_REG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.setBit<TOD_M_PATH_1_STEP_STEER_REG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]

//>> CLEAR_[TOD_M_PATH_1_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_1_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_1_STEP_STEER_REG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_1_STEP_STEER_REG_MODE]

//>> GET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_1_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_1_STEP_STEER_REG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]

//>> GET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]
static inline bool GET_TOD_M_PATH_1_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return i_data.getBit<TOD_M_PATH_1_STEP_STEER_REG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_1_STEP_STEER_REG_MODE]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_RATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_1_STEP_STEER_REG_RATE,
           TOD_M_PATH_1_STEP_STEER_REG_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_RATE]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_RATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_1_STEP_STEER_REG_RATE,
           TOD_M_PATH_1_STEP_STEER_REG_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_RATE]

//>> GET_[TOD_M_PATH_1_STEP_STEER_REG_RATE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_1_STEP_STEER_REG_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_1_STEP_STEER_REG_RATE,
           TOD_M_PATH_1_STEP_STEER_REG_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_1_STEP_STEER_REG_RATE]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.setBit<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> CLEAR_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> GET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> GET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline bool GET_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return i_data.getBit<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE,
           TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE]

//>> SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE,
           TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE]

//>> GET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_1_STEP_STEER_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE,
           TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE]

//>> PREP_[TRA0_TR1_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR1_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA0_TR1_CONFIG_3]

//>> GET_[TRA0_TR1_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR1_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TRA0_TR1_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA0_TR1_CONFIG_3]

//>> PUT_[TRA0_TR1_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TRA0_TR1_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA0_TR1_CONFIG_3]


//>> SET_[TRA0_TR1_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA0_TR1_CONFIG_3_C,
           TRA0_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR1_CONFIG_3_C]

//>> SET_[TRA0_TR1_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR1_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA0_TR1_CONFIG_3_C,
           TRA0_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR1_CONFIG_3_C]

//>> GET_[TRA0_TR1_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TRA0_TR1_CONFIG_3_C,
           TRA0_TR1_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR1_CONFIG_3_C]

//>> SET_[TRA0_TR1_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA0_TR1_CONFIG_3_D,
           TRA0_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR1_CONFIG_3_D]

//>> SET_[TRA0_TR1_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR1_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA0_TR1_CONFIG_3_D,
           TRA0_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR1_CONFIG_3_D]

//>> GET_[TRA0_TR1_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TRA0_TR1_CONFIG_3_D,
           TRA0_TR1_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR1_CONFIG_3_D]

//>> PREP_[TRA1_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA1_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR0_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA1_TR0_CONFIG_5]

//>> GET_[TRA1_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA1_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR0_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TRA1_TR0_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA1_TR0_CONFIG_5]

//>> PUT_[TRA1_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA1_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TRA1_TR0_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA1_TR0_CONFIG_5]


//>> SET_[TRA1_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_5_C,
           TRA1_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_CONFIG_5_C]

//>> SET_[TRA1_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_5_C,
           TRA1_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_CONFIG_5_C]

//>> GET_[TRA1_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_5_C,
           TRA1_TR0_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_CONFIG_5_C]

//>> SET_[TRA1_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_5_D,
           TRA1_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_CONFIG_5_D]

//>> SET_[TRA1_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_5_D,
           TRA1_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_CONFIG_5_D]

//>> GET_[TRA1_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_5_D,
           TRA1_TR0_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_CONFIG_5_D]

//>> PREP_[TRA2_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA2_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA2_TR0_CONFIG_2]

//>> GET_[TRA2_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA2_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TRA2_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA2_TR0_CONFIG_2]

//>> PUT_[TRA2_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA2_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TRA2_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA2_TR0_CONFIG_2]


//>> SET_[TRA2_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_2_A,
           TRA2_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA2_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR0_CONFIG_2_A]

//>> SET_[TRA2_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_2_A,
           TRA2_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA2_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR0_CONFIG_2_A]

//>> GET_[TRA2_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_2_A,
           TRA2_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA2_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA2_TR0_CONFIG_2_A]

//>> SET_[TRA2_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_2_B,
           TRA2_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA2_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR0_CONFIG_2_B]

//>> SET_[TRA2_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_2_B,
           TRA2_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA2_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR0_CONFIG_2_B]

//>> GET_[TRA2_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_2_B,
           TRA2_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA2_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA2_TR0_CONFIG_2_B]

//>> PREP_[TRA3_TR1_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA3_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA3_TR1_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA3_TR1_CONFIG_4]

//>> GET_[TRA3_TR1_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA3_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA3_TR1_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TRA3_TR1_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA3_TR1_CONFIG_4]

//>> PUT_[TRA3_TR1_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA3_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA3_TR1_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TRA3_TR1_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA3_TR1_CONFIG_4]


//>> SET_[TRA3_TR1_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA3_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA3_TR1_CONFIG_4_A,
           TRA3_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA3_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA3_TR1_CONFIG_4_A]

//>> SET_[TRA3_TR1_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA3_TR1_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA3_TR1_CONFIG_4_A,
           TRA3_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA3_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA3_TR1_CONFIG_4_A]

//>> GET_[TRA3_TR1_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& GET_TRA3_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TRA3_TR1_CONFIG_4_A,
           TRA3_TR1_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA3_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA3_TR1_CONFIG_4_A]

//>> SET_[TRA3_TR1_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA3_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA3_TR1_CONFIG_4_B,
           TRA3_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA3_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA3_TR1_CONFIG_4_B]

//>> SET_[TRA3_TR1_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA3_TR1_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA3_TR1_CONFIG_4_B,
           TRA3_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA3_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA3_TR1_CONFIG_4_B]

//>> GET_[TRA3_TR1_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& GET_TRA3_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TRA3_TR1_CONFIG_4_B,
           TRA3_TR1_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA3_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA3_TR1_CONFIG_4_B]

//>> PREP_[TRA4_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA4_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA4_TR0_TRACE_LO_DATA_REG]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA4_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA4_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG]

//>> PUT_[TRA4_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA4_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA4_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA4_TR0_TRACE_LO_DATA_REG]


//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> CLEAR_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline bool GET_TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> CLEAR_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline bool GET_TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA4_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> CLEAR_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA4_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA4_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline bool GET_TRA4_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA4_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> SET_[TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> GET_[TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> PREP_[TRA4_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA4_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR1_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA4_TR1_CONFIG_5]

//>> GET_[TRA4_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA4_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR1_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TRA4_TR1_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA4_TR1_CONFIG_5]

//>> PUT_[TRA4_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA4_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA4_TR1_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TRA4_TR1_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA4_TR1_CONFIG_5]


//>> SET_[TRA4_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA4_TR1_CONFIG_5_C,
           TRA4_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR1_CONFIG_5_C]

//>> SET_[TRA4_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA4_TR1_CONFIG_5_C,
           TRA4_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR1_CONFIG_5_C]

//>> GET_[TRA4_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<TRA4_TR1_CONFIG_5_C,
           TRA4_TR1_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR1_CONFIG_5_C]

//>> SET_[TRA4_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA4_TR1_CONFIG_5_D,
           TRA4_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR1_CONFIG_5_D]

//>> SET_[TRA4_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA4_TR1_CONFIG_5_D,
           TRA4_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR1_CONFIG_5_D]

//>> GET_[TRA4_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<TRA4_TR1_CONFIG_5_D,
           TRA4_TR1_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR1_CONFIG_5_D]

//>> PREP_[TRA5_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA5_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA5_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA5_TR0_CONFIG_3]

//>> GET_[TRA5_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA5_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA5_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TRA5_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA5_TR0_CONFIG_3]

//>> PUT_[TRA5_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA5_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA5_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TRA5_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA5_TR0_CONFIG_3]


//>> SET_[TRA5_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_TRA5_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA5_TR0_CONFIG_3_C,
           TRA5_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA5_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA5_TR0_CONFIG_3_C]

//>> SET_[TRA5_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_TRA5_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA5_TR0_CONFIG_3_C,
           TRA5_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA5_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA5_TR0_CONFIG_3_C]

//>> GET_[TRA5_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& GET_TRA5_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TRA5_TR0_CONFIG_3_C,
           TRA5_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA5_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA5_TR0_CONFIG_3_C]

//>> SET_[TRA5_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_TRA5_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA5_TR0_CONFIG_3_D,
           TRA5_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA5_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA5_TR0_CONFIG_3_D]

//>> SET_[TRA5_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_TRA5_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA5_TR0_CONFIG_3_D,
           TRA5_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA5_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA5_TR0_CONFIG_3_D]

//>> GET_[TRA5_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& GET_TRA5_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TRA5_TR0_CONFIG_3_D,
           TRA5_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA5_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA5_TR0_CONFIG_3_D]

//>> PREP_[TRA6_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA6_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA6_TR0_CONFIG_4]

//>> GET_[TRA6_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA6_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TRA6_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA6_TR0_CONFIG_4]

//>> PUT_[TRA6_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA6_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA6_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TRA6_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA6_TR0_CONFIG_4]


//>> SET_[TRA6_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA6_TR0_CONFIG_4_A,
           TRA6_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR0_CONFIG_4_A]

//>> SET_[TRA6_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA6_TR0_CONFIG_4_A,
           TRA6_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR0_CONFIG_4_A]

//>> GET_[TRA6_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TRA6_TR0_CONFIG_4_A,
           TRA6_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR0_CONFIG_4_A]

//>> SET_[TRA6_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA6_TR0_CONFIG_4_B,
           TRA6_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR0_CONFIG_4_B]

//>> SET_[TRA6_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA6_TR0_CONFIG_4_B,
           TRA6_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR0_CONFIG_4_B]

//>> GET_[TRA6_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TRA6_TR0_CONFIG_4_B,
           TRA6_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR0_CONFIG_4_B]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
