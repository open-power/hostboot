/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00014.H $         */
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

#ifndef __PERV_REG00014_H_
#define __PERV_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[EPS_THERM_WSUB_CONTROL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_CONTROL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_CONTROL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB_CONTROL_REG]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_CONTROL_REG;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_CONTROL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG]

//>> PUT_[EPS_THERM_WSUB_CONTROL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_CONTROL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB_CONTROL_REG]


//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]

//>> SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]

//>> CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]

//>> GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]
static inline bool GET_EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_CONTROL_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR]


//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD,
           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL6_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL6_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL6_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL6_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL6_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL6_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL6_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM,
           FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31,
           FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31,
           FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31,
           FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW]


//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2]

//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2]

//>> PREP_[HANG_PULSE_0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[HANG_PULSE_0_REG]

//>> GET_[HANG_PULSE_0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_0_REG;
#endif
    return fapi2::getScom(i_target, HANG_PULSE_0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[HANG_PULSE_0_REG]

//>> PUT_[HANG_PULSE_0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return fapi2::putScom(i_target, HANG_PULSE_0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[HANG_PULSE_0_REG]


//>> SET_[HANG_PULSE_0_REG_HANG_PULSE_REG_0]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_0_REG_HANG_PULSE_REG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_0_REG_HANG_PULSE_REG_0]

//>> SET_[HANG_PULSE_0_REG_HANG_PULSE_REG_0]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_0_REG_HANG_PULSE_REG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_0_REG_HANG_PULSE_REG_0]

//>> GET_[HANG_PULSE_0_REG_HANG_PULSE_REG_0]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_0_REG_HANG_PULSE_REG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_0_REG_HANG_PULSE_REG_0]

//>> SET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> SET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_0_REG_SUPPRESS_HANG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> SET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return o_data.setBit<HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> CLEAR_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& CLEAR_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return o_data.clearBit<HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> GET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> GET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline bool GET_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_0_REG));
#endif
    return i_data.getBit<HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> PREP_[HANG_PULSE_1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[HANG_PULSE_1_REG]

//>> GET_[HANG_PULSE_1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_1_REG;
#endif
    return fapi2::getScom(i_target, HANG_PULSE_1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[HANG_PULSE_1_REG]

//>> PUT_[HANG_PULSE_1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return fapi2::putScom(i_target, HANG_PULSE_1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[HANG_PULSE_1_REG]


//>> SET_[HANG_PULSE_1_REG_HANG_PULSE_REG_1]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_1_REG_HANG_PULSE_REG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_1_REG_HANG_PULSE_REG_1]

//>> SET_[HANG_PULSE_1_REG_HANG_PULSE_REG_1]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_1_REG_HANG_PULSE_REG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_1_REG_HANG_PULSE_REG_1]

//>> GET_[HANG_PULSE_1_REG_HANG_PULSE_REG_1]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_1_REG_HANG_PULSE_REG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_1_REG_HANG_PULSE_REG_1]

//>> SET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> SET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_1_REG_SUPPRESS_HANG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> SET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return o_data.setBit<HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> CLEAR_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& CLEAR_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return o_data.clearBit<HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> GET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> GET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline bool GET_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_1_REG));
#endif
    return i_data.getBit<HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> PREP_[HANG_PULSE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[HANG_PULSE_2_REG]

//>> GET_[HANG_PULSE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_2_REG;
#endif
    return fapi2::getScom(i_target, HANG_PULSE_2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[HANG_PULSE_2_REG]

//>> PUT_[HANG_PULSE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return fapi2::putScom(i_target, HANG_PULSE_2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[HANG_PULSE_2_REG]


//>> SET_[HANG_PULSE_2_REG_HANG_PULSE_REG_2]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_2_REG_HANG_PULSE_REG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_2_REG_HANG_PULSE_REG_2]

//>> SET_[HANG_PULSE_2_REG_HANG_PULSE_REG_2]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_2_REG_HANG_PULSE_REG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_2_REG_HANG_PULSE_REG_2]

//>> GET_[HANG_PULSE_2_REG_HANG_PULSE_REG_2]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_2_REG_HANG_PULSE_REG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_2_REG_HANG_PULSE_REG_2]

//>> SET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> SET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_2_REG_SUPPRESS_HANG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> SET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return o_data.setBit<HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> CLEAR_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& CLEAR_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return o_data.clearBit<HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> GET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> GET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline bool GET_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_2_REG));
#endif
    return i_data.getBit<HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> PREP_[HANG_PULSE_3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_3_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[HANG_PULSE_3_REG]

//>> GET_[HANG_PULSE_3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_3_REG;
#endif
    return fapi2::getScom(i_target, HANG_PULSE_3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[HANG_PULSE_3_REG]

//>> PUT_[HANG_PULSE_3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return fapi2::putScom(i_target, HANG_PULSE_3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[HANG_PULSE_3_REG]


//>> SET_[HANG_PULSE_3_REG_HANG_PULSE_REG_3]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_3_REG_HANG_PULSE_REG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_3_REG_HANG_PULSE_REG_3]

//>> SET_[HANG_PULSE_3_REG_HANG_PULSE_REG_3]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_3_REG_HANG_PULSE_REG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_3_REG_HANG_PULSE_REG_3]

//>> GET_[HANG_PULSE_3_REG_HANG_PULSE_REG_3]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_3_REG_HANG_PULSE_REG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_3_REG_HANG_PULSE_REG_3]

//>> SET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> SET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_3_REG_SUPPRESS_HANG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> SET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return o_data.setBit<HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> CLEAR_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& CLEAR_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return o_data.clearBit<HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> GET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> GET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline bool GET_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_3_REG));
#endif
    return i_data.getBit<HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> PREP_[HANG_PULSE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_4_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[HANG_PULSE_4_REG]

//>> GET_[HANG_PULSE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_4_REG;
#endif
    return fapi2::getScom(i_target, HANG_PULSE_4_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[HANG_PULSE_4_REG]

//>> PUT_[HANG_PULSE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return fapi2::putScom(i_target, HANG_PULSE_4_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[HANG_PULSE_4_REG]


//>> SET_[HANG_PULSE_4_REG_HANG_PULSE_REG_4]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_4_REG_HANG_PULSE_REG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_4_REG_HANG_PULSE_REG_4]

//>> SET_[HANG_PULSE_4_REG_HANG_PULSE_REG_4]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_4_REG_HANG_PULSE_REG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_4_REG_HANG_PULSE_REG_4]

//>> GET_[HANG_PULSE_4_REG_HANG_PULSE_REG_4]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_4_REG_HANG_PULSE_REG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_4_REG_HANG_PULSE_REG_4]

//>> SET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> SET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_4_REG_SUPPRESS_HANG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> SET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return o_data.setBit<HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> CLEAR_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& CLEAR_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return o_data.clearBit<HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> GET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> GET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline bool GET_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_4_REG));
#endif
    return i_data.getBit<HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> PREP_[HANG_PULSE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_5_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[HANG_PULSE_5_REG]

//>> GET_[HANG_PULSE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = HANG_PULSE_5_REG;
#endif
    return fapi2::getScom(i_target, HANG_PULSE_5_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[HANG_PULSE_5_REG]

//>> PUT_[HANG_PULSE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return fapi2::putScom(i_target, HANG_PULSE_5_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[HANG_PULSE_5_REG]


//>> SET_[HANG_PULSE_5_REG_HANG_PULSE_REG_5]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_5_REG_HANG_PULSE_REG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_5_REG_HANG_PULSE_REG_5]

//>> SET_[HANG_PULSE_5_REG_HANG_PULSE_REG_5]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_5_REG_HANG_PULSE_REG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_5_REG_HANG_PULSE_REG_5]

//>> GET_[HANG_PULSE_5_REG_HANG_PULSE_REG_5]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_5_REG_HANG_PULSE_REG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_5_REG_HANG_PULSE_REG_5]

//>> SET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> SET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_5_REG_SUPPRESS_HANG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> SET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& SET_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return o_data.setBit<HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> CLEAR_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& CLEAR_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return o_data.clearBit<HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> GET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& GET_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> GET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline bool GET_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(HANG_PULSE_5_REG));
#endif
    return i_data.getBit<HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> PREP_[OPCG_CAPT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_CAPT2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_CAPT2]

//>> GET_[OPCG_CAPT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_CAPT2(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT2;
#endif
    return fapi2::getScom(i_target, OPCG_CAPT2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_CAPT2]

//>> PUT_[OPCG_CAPT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_CAPT2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return fapi2::putScom(i_target, OPCG_CAPT2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_CAPT2]


//>> SET_[OPCG_CAPT2_13_01EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_13_01EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_13_01EVEN,
           OPCG_CAPT2_13_01EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_13_01EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_13_01EVEN]

//>> SET_[OPCG_CAPT2_13_01EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_13_01EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_13_01EVEN,
           OPCG_CAPT2_13_01EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_13_01EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_13_01EVEN]

//>> GET_[OPCG_CAPT2_13_01EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_13_01EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_13_01EVEN,
           OPCG_CAPT2_13_01EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_13_01EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_13_01EVEN]

//>> SET_[OPCG_CAPT2_14_01ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_14_01ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_14_01ODD,
           OPCG_CAPT2_14_01ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_14_01ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_14_01ODD]

//>> SET_[OPCG_CAPT2_14_01ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_14_01ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_14_01ODD,
           OPCG_CAPT2_14_01ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_14_01ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_14_01ODD]

//>> GET_[OPCG_CAPT2_14_01ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_14_01ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_14_01ODD,
           OPCG_CAPT2_14_01ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_14_01ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_14_01ODD]

//>> SET_[OPCG_CAPT2_15_02EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_15_02EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_15_02EVEN,
           OPCG_CAPT2_15_02EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_15_02EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_15_02EVEN]

//>> SET_[OPCG_CAPT2_15_02EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_15_02EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_15_02EVEN,
           OPCG_CAPT2_15_02EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_15_02EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_15_02EVEN]

//>> GET_[OPCG_CAPT2_15_02EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_15_02EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_15_02EVEN,
           OPCG_CAPT2_15_02EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_15_02EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_15_02EVEN]

//>> SET_[OPCG_CAPT2_16_02ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_16_02ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_16_02ODD,
           OPCG_CAPT2_16_02ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_16_02ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_16_02ODD]

//>> SET_[OPCG_CAPT2_16_02ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_16_02ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_16_02ODD,
           OPCG_CAPT2_16_02ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_16_02ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_16_02ODD]

//>> GET_[OPCG_CAPT2_16_02ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_16_02ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_16_02ODD,
           OPCG_CAPT2_16_02ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_16_02ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_16_02ODD]

//>> SET_[OPCG_CAPT2_17_03EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_17_03EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_17_03EVEN,
           OPCG_CAPT2_17_03EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_17_03EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_17_03EVEN]

//>> SET_[OPCG_CAPT2_17_03EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_17_03EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_17_03EVEN,
           OPCG_CAPT2_17_03EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_17_03EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_17_03EVEN]

//>> GET_[OPCG_CAPT2_17_03EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_17_03EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_17_03EVEN,
           OPCG_CAPT2_17_03EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_17_03EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_17_03EVEN]

//>> SET_[OPCG_CAPT2_18_03ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_18_03ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_18_03ODD,
           OPCG_CAPT2_18_03ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_18_03ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_18_03ODD]

//>> SET_[OPCG_CAPT2_18_03ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_18_03ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_18_03ODD,
           OPCG_CAPT2_18_03ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_18_03ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_18_03ODD]

//>> GET_[OPCG_CAPT2_18_03ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_18_03ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_18_03ODD,
           OPCG_CAPT2_18_03ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_18_03ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_18_03ODD]

//>> SET_[OPCG_CAPT2_19_04EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_19_04EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_19_04EVEN,
           OPCG_CAPT2_19_04EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_19_04EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_19_04EVEN]

//>> SET_[OPCG_CAPT2_19_04EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_19_04EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_19_04EVEN,
           OPCG_CAPT2_19_04EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_19_04EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_19_04EVEN]

//>> GET_[OPCG_CAPT2_19_04EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_19_04EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_19_04EVEN,
           OPCG_CAPT2_19_04EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_19_04EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_19_04EVEN]

//>> SET_[OPCG_CAPT2_20_04ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_20_04ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_20_04ODD,
           OPCG_CAPT2_20_04ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_20_04ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_20_04ODD]

//>> SET_[OPCG_CAPT2_20_04ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_20_04ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_20_04ODD,
           OPCG_CAPT2_20_04ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_20_04ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_20_04ODD]

//>> GET_[OPCG_CAPT2_20_04ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_20_04ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_20_04ODD,
           OPCG_CAPT2_20_04ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_20_04ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_20_04ODD]

//>> SET_[OPCG_CAPT2_21_05EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_21_05EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_21_05EVEN,
           OPCG_CAPT2_21_05EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_21_05EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_21_05EVEN]

//>> SET_[OPCG_CAPT2_21_05EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_21_05EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_21_05EVEN,
           OPCG_CAPT2_21_05EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_21_05EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_21_05EVEN]

//>> GET_[OPCG_CAPT2_21_05EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_21_05EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_21_05EVEN,
           OPCG_CAPT2_21_05EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_21_05EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_21_05EVEN]

//>> SET_[OPCG_CAPT2_22_05ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_22_05ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_22_05ODD,
           OPCG_CAPT2_22_05ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_22_05ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_22_05ODD]

//>> SET_[OPCG_CAPT2_22_05ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_22_05ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_22_05ODD,
           OPCG_CAPT2_22_05ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_22_05ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_22_05ODD]

//>> GET_[OPCG_CAPT2_22_05ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_22_05ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_22_05ODD,
           OPCG_CAPT2_22_05ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_22_05ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_22_05ODD]

//>> SET_[OPCG_CAPT2_23_06EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_23_06EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_23_06EVEN,
           OPCG_CAPT2_23_06EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_23_06EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_23_06EVEN]

//>> SET_[OPCG_CAPT2_23_06EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_23_06EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_23_06EVEN,
           OPCG_CAPT2_23_06EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_23_06EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_23_06EVEN]

//>> GET_[OPCG_CAPT2_23_06EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_23_06EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_23_06EVEN,
           OPCG_CAPT2_23_06EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_23_06EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_23_06EVEN]

//>> SET_[OPCG_CAPT2_24_06ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_24_06ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_24_06ODD,
           OPCG_CAPT2_24_06ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT2_24_06ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_24_06ODD]

//>> SET_[OPCG_CAPT2_24_06ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT2_24_06ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return o_data.insertFromRight<OPCG_CAPT2_24_06ODD,
           OPCG_CAPT2_24_06ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT2_24_06ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT2_24_06ODD]

//>> GET_[OPCG_CAPT2_24_06ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT2_24_06ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT2));
#endif
    return i_data.extractToRight<OPCG_CAPT2_24_06ODD,
           OPCG_CAPT2_24_06ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT2_24_06ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_24_06ODD]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG0]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG0;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG0]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG0));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG0]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG0));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0,
           SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG0));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0,
           SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG0));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0,
           SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
