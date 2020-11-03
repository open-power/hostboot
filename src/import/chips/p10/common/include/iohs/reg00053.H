/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00053.H $         */
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

#ifndef __IOHS_REG00053_H_
#define __IOHS_REG00053_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_CONTROL]

//>> GET_[DLP_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_CONTROL(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_CONTROL;
#endif
    return fapi2::getScom(i_target, DLP_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_CONTROL]

//>> PUT_[DLP_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_CONTROL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return fapi2::putScom(i_target, DLP_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_CONTROL]


//>> SET_[DLP_CONTROL_0_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_PHY_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_PHY_TRAINING]

//>> SET_[DLP_CONTROL_0_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_PHY_TRAINING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_PHY_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_PHY_TRAINING]

//>> SET_[DLP_CONTROL_0_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_PHY_TRAINING]

//>> CLEAR_[DLP_CONTROL_0_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_0_PHY_TRAINING]

//>> GET_[DLP_CONTROL_0_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_PHY_TRAINING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_PHY_TRAINING]

//>> GET_[DLP_CONTROL_0_PHY_TRAINING]
static inline bool GET_DLP_CONTROL_0_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_0_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_PHY_TRAINING]

//>> SET_[DLP_CONTROL_0_STARTUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_STARTUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_STARTUP]

//>> SET_[DLP_CONTROL_0_STARTUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_STARTUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_STARTUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_STARTUP]

//>> SET_[DLP_CONTROL_0_STARTUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_STARTUP]

//>> CLEAR_[DLP_CONTROL_0_STARTUP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_0_STARTUP]

//>> GET_[DLP_CONTROL_0_STARTUP]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_STARTUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_STARTUP]

//>> GET_[DLP_CONTROL_0_STARTUP]
static inline bool GET_DLP_CONTROL_0_STARTUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_0_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_STARTUP]

//>> SET_[DLP_CONTROL_0_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_HOLD_PATT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_HOLD_PATT_A]

//>> SET_[DLP_CONTROL_0_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_HOLD_PATT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_HOLD_PATT_A]

//>> SET_[DLP_CONTROL_0_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_HOLD_PATT_A]

//>> CLEAR_[DLP_CONTROL_0_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_0_HOLD_PATT_A]

//>> GET_[DLP_CONTROL_0_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_HOLD_PATT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_HOLD_PATT_A]

//>> GET_[DLP_CONTROL_0_HOLD_PATT_A]
static inline bool GET_DLP_CONTROL_0_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_HOLD_PATT_A]

//>> SET_[DLP_CONTROL_0_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_HOLD_PATT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_HOLD_PATT_B]

//>> SET_[DLP_CONTROL_0_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_HOLD_PATT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_HOLD_PATT_B]

//>> SET_[DLP_CONTROL_0_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_HOLD_PATT_B]

//>> CLEAR_[DLP_CONTROL_0_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_0_HOLD_PATT_B]

//>> GET_[DLP_CONTROL_0_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_HOLD_PATT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_HOLD_PATT_B]

//>> GET_[DLP_CONTROL_0_HOLD_PATT_B]
static inline bool GET_DLP_CONTROL_0_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_0_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_HOLD_PATT_B]

//>> SET_[DLP_CONTROL_0_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_RUN_LANE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_RUN_LANE_DISABLE]

//>> SET_[DLP_CONTROL_0_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_RUN_LANE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_RUN_LANE_DISABLE]

//>> SET_[DLP_CONTROL_0_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_RUN_LANE_DISABLE]

//>> CLEAR_[DLP_CONTROL_0_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_0_RUN_LANE_DISABLE]

//>> GET_[DLP_CONTROL_0_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_RUN_LANE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_RUN_LANE_DISABLE]

//>> GET_[DLP_CONTROL_0_RUN_LANE_DISABLE]
static inline bool GET_DLP_CONTROL_0_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_RUN_LANE_DISABLE]

//>> SET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_RUN_LANE_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]

//>> SET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_RUN_LANE_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]

//>> SET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]

//>> CLEAR_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]

//>> GET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_RUN_LANE_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]

//>> GET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]
static inline bool GET_DLP_CONTROL_0_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_0_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_RUN_LANE_OVERRIDE]

//>> SET_[DLP_CONTROL_0_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_IGNORE_PHY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_IGNORE_PHY]

//>> SET_[DLP_CONTROL_0_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_PHY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_IGNORE_PHY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_IGNORE_PHY]

//>> SET_[DLP_CONTROL_0_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_IGNORE_PHY]

//>> CLEAR_[DLP_CONTROL_0_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_0_IGNORE_PHY]

//>> GET_[DLP_CONTROL_0_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_IGNORE_PHY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_IGNORE_PHY]

//>> GET_[DLP_CONTROL_0_IGNORE_PHY]
static inline bool GET_DLP_CONTROL_0_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_IGNORE_PHY]

//>> SET_[DLP_CONTROL_0_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_IGNORE_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_IGNORE_FENCE]

//>> SET_[DLP_CONTROL_0_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_IGNORE_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_IGNORE_FENCE]

//>> SET_[DLP_CONTROL_0_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_0_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_IGNORE_FENCE]

//>> CLEAR_[DLP_CONTROL_0_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_0_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_0_IGNORE_FENCE]

//>> GET_[DLP_CONTROL_0_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_IGNORE_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_IGNORE_FENCE]

//>> GET_[DLP_CONTROL_0_IGNORE_FENCE]
static inline bool GET_DLP_CONTROL_0_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_0_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_0_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_IGNORE_FENCE]

//>> SET_[DLP_CONTROL_0_ERR_INJ_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_ERR_INJ_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_ERR_INJ_COMMAND,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_ERR_INJ_COMMAND]

//>> SET_[DLP_CONTROL_0_ERR_INJ_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_ERR_INJ_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_ERR_INJ_COMMAND,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_ERR_INJ_COMMAND]

//>> GET_[DLP_CONTROL_0_ERR_INJ_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_ERR_INJ_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_ERR_INJ_COMMAND,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_ERR_INJ_COMMAND]

//>> SET_[DLP_CONTROL_0_ERR_INJ_COMMAND_LANES]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_ERR_INJ_COMMAND_LANES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_ERR_INJ_COMMAND_LANES]

//>> SET_[DLP_CONTROL_0_ERR_INJ_COMMAND_LANES]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_ERR_INJ_COMMAND_LANES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_ERR_INJ_COMMAND_LANES]

//>> GET_[DLP_CONTROL_0_ERR_INJ_COMMAND_LANES]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_ERR_INJ_COMMAND_LANES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_0_ERR_INJ_COMMAND_LANES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_ERR_INJ_COMMAND_LANES]

//>> SET_[DLP_CONTROL_0_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_COMMAND,
           DLP_CONTROL_0_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_0_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_COMMAND]

//>> SET_[DLP_CONTROL_0_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_0_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_0_COMMAND,
           DLP_CONTROL_0_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_0_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_0_COMMAND]

//>> GET_[DLP_CONTROL_0_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_0_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_0_COMMAND,
           DLP_CONTROL_0_COMMAND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_0_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_0_COMMAND]

//>> SET_[DLP_CONTROL_1_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_PHY_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_PHY_TRAINING]

//>> SET_[DLP_CONTROL_1_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_PHY_TRAINING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_PHY_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_PHY_TRAINING]

//>> SET_[DLP_CONTROL_1_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_PHY_TRAINING]

//>> CLEAR_[DLP_CONTROL_1_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_1_PHY_TRAINING]

//>> GET_[DLP_CONTROL_1_PHY_TRAINING]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_PHY_TRAINING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_PHY_TRAINING]

//>> GET_[DLP_CONTROL_1_PHY_TRAINING]
static inline bool GET_DLP_CONTROL_1_PHY_TRAINING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_PHY_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_1_PHY_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_PHY_TRAINING]

//>> SET_[DLP_CONTROL_1_STARTUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_STARTUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_STARTUP]

//>> SET_[DLP_CONTROL_1_STARTUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_STARTUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_STARTUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_STARTUP]

//>> SET_[DLP_CONTROL_1_STARTUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_STARTUP]

//>> CLEAR_[DLP_CONTROL_1_STARTUP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_1_STARTUP]

//>> GET_[DLP_CONTROL_1_STARTUP]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_STARTUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_STARTUP]

//>> GET_[DLP_CONTROL_1_STARTUP]
static inline bool GET_DLP_CONTROL_1_STARTUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_STARTUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_1_STARTUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_STARTUP]

//>> SET_[DLP_CONTROL_1_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_HOLD_PATT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_HOLD_PATT_A]

//>> SET_[DLP_CONTROL_1_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_HOLD_PATT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_HOLD_PATT_A]

//>> SET_[DLP_CONTROL_1_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_HOLD_PATT_A]

//>> CLEAR_[DLP_CONTROL_1_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_1_HOLD_PATT_A]

//>> GET_[DLP_CONTROL_1_HOLD_PATT_A]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_HOLD_PATT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_HOLD_PATT_A]

//>> GET_[DLP_CONTROL_1_HOLD_PATT_A]
static inline bool GET_DLP_CONTROL_1_HOLD_PATT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_HOLD_PATT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_HOLD_PATT_A]

//>> SET_[DLP_CONTROL_1_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_HOLD_PATT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_HOLD_PATT_B]

//>> SET_[DLP_CONTROL_1_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_HOLD_PATT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_HOLD_PATT_B]

//>> SET_[DLP_CONTROL_1_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_HOLD_PATT_B]

//>> CLEAR_[DLP_CONTROL_1_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_1_HOLD_PATT_B]

//>> GET_[DLP_CONTROL_1_HOLD_PATT_B]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_HOLD_PATT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_HOLD_PATT_B]

//>> GET_[DLP_CONTROL_1_HOLD_PATT_B]
static inline bool GET_DLP_CONTROL_1_HOLD_PATT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_HOLD_PATT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_1_HOLD_PATT_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_HOLD_PATT_B]

//>> SET_[DLP_CONTROL_1_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_RUN_LANE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_RUN_LANE_DISABLE]

//>> SET_[DLP_CONTROL_1_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_RUN_LANE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_RUN_LANE_DISABLE]

//>> SET_[DLP_CONTROL_1_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_RUN_LANE_DISABLE]

//>> CLEAR_[DLP_CONTROL_1_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_1_RUN_LANE_DISABLE]

//>> GET_[DLP_CONTROL_1_RUN_LANE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_RUN_LANE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_RUN_LANE_DISABLE]

//>> GET_[DLP_CONTROL_1_RUN_LANE_DISABLE]
static inline bool GET_DLP_CONTROL_1_RUN_LANE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_RUN_LANE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_RUN_LANE_DISABLE]

//>> SET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_RUN_LANE_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]

//>> SET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_RUN_LANE_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]

//>> SET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]

//>> CLEAR_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]

//>> GET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_RUN_LANE_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]

//>> GET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]
static inline bool GET_DLP_CONTROL_1_RUN_LANE_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_RUN_LANE_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_1_RUN_LANE_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_RUN_LANE_OVERRIDE]

//>> SET_[DLP_CONTROL_1_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_IGNORE_PHY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_IGNORE_PHY]

//>> SET_[DLP_CONTROL_1_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_PHY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_IGNORE_PHY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_IGNORE_PHY]

//>> SET_[DLP_CONTROL_1_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_IGNORE_PHY]

//>> CLEAR_[DLP_CONTROL_1_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_1_IGNORE_PHY]

//>> GET_[DLP_CONTROL_1_IGNORE_PHY]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_IGNORE_PHY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_IGNORE_PHY]

//>> GET_[DLP_CONTROL_1_IGNORE_PHY]
static inline bool GET_DLP_CONTROL_1_IGNORE_PHY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_IGNORE_PHY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_PHY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_IGNORE_PHY]

//>> SET_[DLP_CONTROL_1_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_IGNORE_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_IGNORE_FENCE]

//>> SET_[DLP_CONTROL_1_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_IGNORE_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_IGNORE_FENCE]

//>> SET_[DLP_CONTROL_1_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.setBit<DLP_CONTROL_1_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_IGNORE_FENCE]

//>> CLEAR_[DLP_CONTROL_1_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.clearBit<DLP_CONTROL_1_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_CONTROL_1_IGNORE_FENCE]

//>> GET_[DLP_CONTROL_1_IGNORE_FENCE]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_IGNORE_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_IGNORE_FENCE]

//>> GET_[DLP_CONTROL_1_IGNORE_FENCE]
static inline bool GET_DLP_CONTROL_1_IGNORE_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.getBit<DLP_CONTROL_1_IGNORE_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_CONTROL_1_IGNORE_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_IGNORE_FENCE]

//>> SET_[DLP_CONTROL_1_ERR_INJ_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_ERR_INJ_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_ERR_INJ_COMMAND,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_ERR_INJ_COMMAND]

//>> SET_[DLP_CONTROL_1_ERR_INJ_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_ERR_INJ_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_ERR_INJ_COMMAND,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_ERR_INJ_COMMAND]

//>> GET_[DLP_CONTROL_1_ERR_INJ_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_ERR_INJ_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_ERR_INJ_COMMAND,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_ERR_INJ_COMMAND]

//>> SET_[DLP_CONTROL_1_ERR_INJ_COMMAND_LANES]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_ERR_INJ_COMMAND_LANES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_ERR_INJ_COMMAND_LANES]

//>> SET_[DLP_CONTROL_1_ERR_INJ_COMMAND_LANES]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_ERR_INJ_COMMAND_LANES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_ERR_INJ_COMMAND_LANES]

//>> GET_[DLP_CONTROL_1_ERR_INJ_COMMAND_LANES]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_ERR_INJ_COMMAND_LANES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_ERR_INJ_COMMAND_LANES,
           DLP_CONTROL_1_ERR_INJ_COMMAND_LANES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_ERR_INJ_COMMAND_LANES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_ERR_INJ_COMMAND_LANES]

//>> SET_[DLP_CONTROL_1_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_COMMAND,
           DLP_CONTROL_1_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_CONTROL_1_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_COMMAND]

//>> SET_[DLP_CONTROL_1_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_DLP_CONTROL_1_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return o_data.insertFromRight<DLP_CONTROL_1_COMMAND,
           DLP_CONTROL_1_COMMAND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_CONTROL_1_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_CONTROL_1_COMMAND]

//>> GET_[DLP_CONTROL_1_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_DLP_CONTROL_1_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_CONTROL));
#endif
    return i_data.extractToRight<DLP_CONTROL_1_COMMAND,
           DLP_CONTROL_1_COMMAND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_CONTROL_1_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_CONTROL_1_COMMAND]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
