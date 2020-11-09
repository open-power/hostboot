/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pec/reg00007.H $          */
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

#ifndef __PEC_REG00007_H_
#define __PEC_REG00007_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT chip: %x, ec: %x",
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
    FAPI_ERR("0:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR]

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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_13_01EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_13_01EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_13_01EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_14_01ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_14_01ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_14_01ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_15_02EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_15_02EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_15_02EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_16_02ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_16_02ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_16_02ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_17_03EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_17_03EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_17_03EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_18_03ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_18_03ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_18_03ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_19_04EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_19_04EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_19_04EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_20_04ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_20_04ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_20_04ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_21_05EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_21_05EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_21_05EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_22_05ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_22_05ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_22_05ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_23_06EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_23_06EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_23_06EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_CAPT2_24_06ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_CAPT2_24_06ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_CAPT2_24_06ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT2_24_06ODD]

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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_INPUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_USE_SYNC_FOR_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_DISABLE_PCB_ITR chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_SYNC_PULSE_OUT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_REGION_PGOOD_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_CONT_SCAN_SHORT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_CONT_SCAN_SHORT_WAIT]

//>> SET_[P10_20_SYNC_CONFIG_PCIE32_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SYNC_CONFIG_PCIE32_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<P10_20_SYNC_CONFIG_PCIE32_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access P10_20_SYNC_CONFIG_PCIE32_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SYNC_CONFIG_PCIE32_MODE]

//>> SET_[P10_20_SYNC_CONFIG_PCIE32_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SYNC_CONFIG_PCIE32_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.insertFromRight<P10_20_SYNC_CONFIG_PCIE32_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access P10_20_SYNC_CONFIG_PCIE32_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SYNC_CONFIG_PCIE32_MODE]

//>> SET_[P10_20_SYNC_CONFIG_PCIE32_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SYNC_CONFIG_PCIE32_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.setBit<P10_20_SYNC_CONFIG_PCIE32_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access P10_20_SYNC_CONFIG_PCIE32_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SYNC_CONFIG_PCIE32_MODE]

//>> CLEAR_[P10_20_SYNC_CONFIG_PCIE32_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SYNC_CONFIG_PCIE32_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return o_data.clearBit<P10_20_SYNC_CONFIG_PCIE32_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access P10_20_SYNC_CONFIG_PCIE32_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SYNC_CONFIG_PCIE32_MODE]

//>> GET_[P10_20_SYNC_CONFIG_PCIE32_MODE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SYNC_CONFIG_PCIE32_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.extractToRight<P10_20_SYNC_CONFIG_PCIE32_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access P10_20_SYNC_CONFIG_PCIE32_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SYNC_CONFIG_PCIE32_MODE]

//>> GET_[P10_20_SYNC_CONFIG_PCIE32_MODE]
static inline bool GET_P10_20_SYNC_CONFIG_PCIE32_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SYNC_CONFIG));
#endif
    return i_data.getBit<P10_20_SYNC_CONFIG_PCIE32_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access P10_20_SYNC_CONFIG_PCIE32_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SYNC_CONFIG_PCIE32_MODE]

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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pec Invalid dial access SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
