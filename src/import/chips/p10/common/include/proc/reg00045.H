/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00045.H $         */
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

#ifndef __PROC_REG00045_H_
#define __PROC_REG00045_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SI1M]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SI1M(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SI1M;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SI1M]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SI1M]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SI1M(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SI1M;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SI1M, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SI1M]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SI1M]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SI1M(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SI1M));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SI1M, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SI1M]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SI2S]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SI2S(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SI2S;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SI2S]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SI2S]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SI2S(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SI2S;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SI2S, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SI2S]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SI2S]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SI2S(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SI2S));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SI2S, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SI2S]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SLASTD_SRES]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SMODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SMODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SMODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SMODE]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SMODE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SMODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SMODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SMODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SMODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SMODE]


//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_WARM_START_COMPLETED]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ENABLE_HW_ERROR_RECOVERY]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_OWN_ID_THIS_SLAVE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_ECHO_DELAY_CYCLES]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_SEND_DELAY_CYCLES]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_FSI_A_LBUS_CLOCK_DIVIDER]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMODE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1,
           TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SMODE_BRIEFING_DATA_TO_SLAVE_SIDE_1]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SRSIM4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SRSIM4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIM4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SRSIM4]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SRSIM4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SRSIM4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIM4;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIM4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SRSIM4]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SRSIM4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SRSIM4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SRSIM4));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIM4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SRSIM4]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SSMBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SSMBL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSMBL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SSMBL]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SSMBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SSMBL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSMBL;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSMBL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SSMBL]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SSMBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SSMBL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SSMBL));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSMBL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SSMBL]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_B_SOML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SOML(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SOML;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_B_SOML]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SOML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SOML(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SOML;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SOML, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SOML]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_B_SOML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SOML(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SOML));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SOML, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_B_SOML]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_PEEK4B0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_PEEK4B0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_PEEK4B0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_PEEK4B0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_PEEK4B0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_PEEK4B0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_PEEK4B0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_PEEK4B0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_PEEK4B0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_PEEK4B0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_PEEK4B0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4B0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_PEEK4B0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_PEEK4B0]


//>> PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_SEQUENCER_OP_REG_SEQUENCER_OP_Q]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]

//>> PREP_[VAS_VA_EG_SCF_CQERRRPT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_CQERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_CQERRRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_EG_SCF_CQERRRPT]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_CQERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_CQERRRPT;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_CQERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT]

//>> PUT_[VAS_VA_EG_SCF_CQERRRPT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_CQERRRPT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_CQERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_EG_SCF_CQERRRPT]


//>> SET_[VAS_VA_EG_SCF_CQERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_RESET]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_RESET]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_RESET]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_RESET]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_RESET]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_RESET]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_RESET]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT4]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT4]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT5]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT5]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT6]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT6]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT7]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT7]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT8]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT8]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT9]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT9]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT10]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT10]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT11]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT11]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT12]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT12]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT13]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT13]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT14]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT14]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT15]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT15]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT16]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT16]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT17]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT17]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT18]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT18]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT19]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT19]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT20]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT20]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT21]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT21]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT22]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT22]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT23]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT23]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT24]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT24]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT24]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT25]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT25]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT25]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT26]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT26]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT26]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT27]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT27]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT27]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT28]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT28]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT28]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT29]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT29]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT29]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT30]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT30]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT30]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT31]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT31]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT31]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT32]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT32]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT32]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT33]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT33]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT33]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT34]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT34]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT34]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT35]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT35]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT35]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT36]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT36]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT36]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT37]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT37]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT37]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT38]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT38]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT38]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_CQERRRPT_BIT39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]

//>> SET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_CQERRRPT_BIT39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]

//>> CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT39]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_CQERRRPT_BIT39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_CQERRRPT_BIT39]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_CQERRRPT_BIT39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]

//>> GET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]
static inline bool GET_VAS_VA_EG_SCF_CQERRRPT_BIT39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_CQERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_CQERRRPT_BIT39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_CQERRRPT_BIT39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_CQERRRPT_BIT39]

//>> PREP_[VAS_VA_EG_SCF_PGMIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_PGMIG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_EG_SCF_PGMIG2]

//>> GET_[VAS_VA_EG_SCF_PGMIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_PGMIG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG2;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_PGMIG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_EG_SCF_PGMIG2]

//>> PUT_[VAS_VA_EG_SCF_PGMIG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_PGMIG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PGMIG2));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_PGMIG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_EG_SCF_PGMIG2]


//>> PREP_[VAS_VA_RG_SCF_DBGNORTH]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_DBGNORTH(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_DBGNORTH;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_DBGNORTH]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_DBGNORTH(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_DBGNORTH;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_DBGNORTH, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH]

//>> PUT_[VAS_VA_RG_SCF_DBGNORTH]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_DBGNORTH(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_DBGNORTH, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_DBGNORTH]


//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRACE_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23,
           VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_TRIGGERS_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_GROUP_SEL_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_TRIGGER_SEL_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_GROUP_SEL_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23,
           VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_TRIGGER_SEL_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_TRACE]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_TRACE]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_SEL_RG_PMU_DATA]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_IN_PMU_COUNTING]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_ENABLE_RG_PMU_COUNTING]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_LO]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_DATA_HI]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_IN_TRACE_INT_TRIG_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_EG_TRACE_INT_TRIG_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_01]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]

//>> SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]

//>> CLEAR_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]

//>> GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]
static inline bool GET_VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGNORTH));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_DBGNORTH_RG_TRACE_INT_TRIG_23]

//>> PREP_[VAS_VA_RG_SCF_WCMBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WCMBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WCMBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_WCMBAR]

//>> GET_[VAS_VA_RG_SCF_WCMBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WCMBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WCMBAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WCMBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_WCMBAR]

//>> PUT_[VAS_VA_RG_SCF_WCMBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WCMBAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WCMBAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WCMBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_WCMBAR]


//>> SET_[VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WCMBAR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR,
           VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR]

//>> SET_[VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WCMBAR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR,
           VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR]

//>> GET_[VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WCMBAR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR,
           VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_WCMBAR_WCMBAR_BASE_ADDR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
