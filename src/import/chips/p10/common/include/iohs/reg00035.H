/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00035.H $         */
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

#ifndef __IOHS_REG00035_H_
#define __IOHS_REG00035_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[AXON_CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_CPLT_CONF1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[AXON_CPLT_CONF1_RW]

//>> GET_[AXON_CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_CPLT_CONF1_RW;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CONF1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[AXON_CPLT_CONF1_RW]

//>> PUT_[AXON_CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CONF1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[AXON_CPLT_CONF1_RW]

//>> PREP_[AXON_CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[AXON_CPLT_CONF1_WO_CLEAR]

//>> GET_[AXON_CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CONF1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[AXON_CPLT_CONF1_WO_CLEAR]

//>> PUT_[AXON_CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CONF1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[AXON_CPLT_CONF1_WO_CLEAR]

//>> PREP_[AXON_CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_CPLT_CONF1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[AXON_CPLT_CONF1_WO_OR]

//>> GET_[AXON_CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_CPLT_CONF1_WO_OR;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CONF1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[AXON_CPLT_CONF1_WO_OR]

//>> PUT_[AXON_CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CONF1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[AXON_CPLT_CONF1_WO_OR]


//>> SET_[AXON_CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF1_OD_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access AXON_CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[AXON_CPLT_CONF1_OD_IOVALID_DC]

//>> SET_[AXON_CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF1_OD_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF1_OD_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access AXON_CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[AXON_CPLT_CONF1_OD_IOVALID_DC]

//>> SET_[AXON_CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<AXON_CPLT_CONF1_OD_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access AXON_CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[AXON_CPLT_CONF1_OD_IOVALID_DC]

//>> CLEAR_[AXON_CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<AXON_CPLT_CONF1_OD_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access AXON_CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[AXON_CPLT_CONF1_OD_IOVALID_DC]

//>> GET_[AXON_CPLT_CONF1_OD_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF1_OD_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access AXON_CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[AXON_CPLT_CONF1_OD_IOVALID_DC]

//>> GET_[AXON_CPLT_CONF1_OD_IOVALID_DC]
static inline bool GET_AXON_CPLT_CONF1_OD_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<AXON_CPLT_CONF1_OD_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access AXON_CPLT_CONF1_OD_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[AXON_CPLT_CONF1_OD_IOVALID_DC]

//>> SET_[AXON_CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF1_EV_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access AXON_CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[AXON_CPLT_CONF1_EV_IOVALID_DC]

//>> SET_[AXON_CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF1_EV_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF1_EV_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access AXON_CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[AXON_CPLT_CONF1_EV_IOVALID_DC]

//>> SET_[AXON_CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<AXON_CPLT_CONF1_EV_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access AXON_CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[AXON_CPLT_CONF1_EV_IOVALID_DC]

//>> CLEAR_[AXON_CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<AXON_CPLT_CONF1_EV_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access AXON_CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[AXON_CPLT_CONF1_EV_IOVALID_DC]

//>> GET_[AXON_CPLT_CONF1_EV_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF1_EV_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access AXON_CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[AXON_CPLT_CONF1_EV_IOVALID_DC]

//>> GET_[AXON_CPLT_CONF1_EV_IOVALID_DC]
static inline bool GET_AXON_CPLT_CONF1_EV_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_CPLT_CONF1_RW, AXON_CPLT_CONF1_WO_CLEAR, AXON_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<AXON_CPLT_CONF1_EV_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access AXON_CPLT_CONF1_EV_IOVALID_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[AXON_CPLT_CONF1_EV_IOVALID_DC]

//>> PREP_[DLP_LINK0_RX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK0_RX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_RX_LANE_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK0_RX_LANE_CONTROL]

//>> GET_[DLP_LINK0_RX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK0_RX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_RX_LANE_CONTROL;
#endif
    return fapi2::getScom(i_target, DLP_LINK0_RX_LANE_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK0_RX_LANE_CONTROL]

//>> PUT_[DLP_LINK0_RX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK0_RX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return fapi2::putScom(i_target, DLP_LINK0_RX_LANE_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK0_RX_LANE_CONTROL]


//>> SET_[DLP_LINK0_RX_LANE_CONTROL_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_DISABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_DISABLED,
           DLP_LINK0_RX_LANE_CONTROL_DISABLED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_DISABLED]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_DISABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_DISABLED,
           DLP_LINK0_RX_LANE_CONTROL_DISABLED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_DISABLED]

//>> GET_[DLP_LINK0_RX_LANE_CONTROL_DISABLED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_RX_LANE_CONTROL_DISABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_RX_LANE_CONTROL_DISABLED,
           DLP_LINK0_RX_LANE_CONTROL_DISABLED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_RX_LANE_CONTROL_DISABLED]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_BRINGUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_BRINGUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_BRINGUP,
           DLP_LINK0_RX_LANE_CONTROL_BRINGUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_BRINGUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_BRINGUP]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_BRINGUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_BRINGUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_BRINGUP,
           DLP_LINK0_RX_LANE_CONTROL_BRINGUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_BRINGUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_BRINGUP]

//>> GET_[DLP_LINK0_RX_LANE_CONTROL_BRINGUP]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_RX_LANE_CONTROL_BRINGUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_RX_LANE_CONTROL_BRINGUP,
           DLP_LINK0_RX_LANE_CONTROL_BRINGUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_BRINGUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_RX_LANE_CONTROL_BRINGUP]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_SPARED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_SPARED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_SPARED,
           DLP_LINK0_RX_LANE_CONTROL_SPARED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_SPARED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_SPARED]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_SPARED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_SPARED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_SPARED,
           DLP_LINK0_RX_LANE_CONTROL_SPARED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_SPARED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_SPARED]

//>> GET_[DLP_LINK0_RX_LANE_CONTROL_SPARED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_RX_LANE_CONTROL_SPARED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_RX_LANE_CONTROL_SPARED,
           DLP_LINK0_RX_LANE_CONTROL_SPARED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_SPARED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_RX_LANE_CONTROL_SPARED]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_LOCKED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_LOCKED,
           DLP_LINK0_RX_LANE_CONTROL_LOCKED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_LOCKED]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_LOCKED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_LOCKED,
           DLP_LINK0_RX_LANE_CONTROL_LOCKED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_LOCKED]

//>> GET_[DLP_LINK0_RX_LANE_CONTROL_LOCKED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_RX_LANE_CONTROL_LOCKED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_RX_LANE_CONTROL_LOCKED,
           DLP_LINK0_RX_LANE_CONTROL_LOCKED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_RX_LANE_CONTROL_LOCKED]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_FAILED,
           DLP_LINK0_RX_LANE_CONTROL_FAILED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_FAILED]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_FAILED,
           DLP_LINK0_RX_LANE_CONTROL_FAILED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_FAILED]

//>> GET_[DLP_LINK0_RX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_RX_LANE_CONTROL_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_RX_LANE_CONTROL_FAILED,
           DLP_LINK0_RX_LANE_CONTROL_FAILED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_RX_LANE_CONTROL_FAILED]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS,
           DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS]

//>> SET_[DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS,
           DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS]

//>> GET_[DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS,
           DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS]

//>> PREP_[DLP_OPTICAL_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_OPTICAL_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_OPTICAL_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_OPTICAL_CONFIG]

//>> GET_[DLP_OPTICAL_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_OPTICAL_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_OPTICAL_CONFIG;
#endif
    return fapi2::getScom(i_target, DLP_OPTICAL_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG]

//>> PUT_[DLP_OPTICAL_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_OPTICAL_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return fapi2::putScom(i_target, DLP_OPTICAL_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_OPTICAL_CONFIG]


//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]

//>> CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]
static inline bool GET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]

//>> CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]
static inline bool GET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]

//>> CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]
static inline bool GET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION,
           DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION,
           DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION,
           DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX,
           DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX,
           DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX,
           DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]

//>> CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]
static inline bool GET_DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION,
           DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION,
           DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION,
           DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX,
           DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX,
           DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX,
           DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX]

//>> SET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]

//>> SET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]

//>> SET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]

//>> CLEAR_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]

//>> GET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]

//>> GET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]
static inline bool GET_DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER]

//>> SET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]

//>> SET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]

//>> SET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]

//>> CLEAR_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]

//>> GET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]

//>> GET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]
static inline bool GET_DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER]

//>> SET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]

//>> CLEAR_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]
static inline bool GET_DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]

//>> CLEAR_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]
static inline bool GET_DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]

//>> CLEAR_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]
static inline bool GET_DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]

//>> CLEAR_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]
static inline bool GET_DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]

//>> CLEAR_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]

//>> GET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]
static inline bool GET_DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH,
           DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]

//>> CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]
static inline bool GET_DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.setBit<DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]

//>> CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.clearBit<DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]
static inline bool GET_DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.getBit<DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT,
           DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT]

//>> SET_[DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return o_data.insertFromRight<DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT,
           DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT]

//>> GET_[DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_OPTICAL_CONFIG));
#endif
    return i_data.extractToRight<DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT,
           DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT]

//>> PREP_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ERROR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ERROR_REG]

//>> GET_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ERROR_REG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_REG;
#endif
    return fapi2::getScom(i_target, ERROR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ERROR_REG]

//>> PUT_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ERROR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return fapi2::putScom(i_target, ERROR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ERROR_REG]


//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> CLEAR_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CE_ERROR]

//>> GET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CE_ERROR]

//>> GET_[ERROR_REG_CE_ERROR]
static inline bool GET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ERRORS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ERRORS]

//>> SET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ERRORS]

//>> GET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_ERRORS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ERRORS]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> CLEAR_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline bool GET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> CLEAR_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline bool GET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> CLEAR_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PCB_FSM_ERROR]

//>> GET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PCB_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_FSM_ERROR]

//>> GET_[ERROR_REG_PCB_FSM_ERROR]
static inline bool GET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> CLEAR_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CL_FSM_ERROR]

//>> GET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CL_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_FSM_ERROR]

//>> GET_[ERROR_REG_CL_FSM_ERROR]
static inline bool GET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> CLEAR_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline bool GET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> CLEAR_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline bool GET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> CLEAR_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_TYPE_ERROR]

//>> GET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_TYPE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TYPE_ERROR]

//>> GET_[ERROR_REG_INT_TYPE_ERROR]
static inline bool GET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> CLEAR_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CL_DATA_ERROR]

//>> GET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CL_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_DATA_ERROR]

//>> GET_[ERROR_REG_CL_DATA_ERROR]
static inline bool GET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> CLEAR_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INFO_ERROR]

//>> GET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INFO_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INFO_ERROR]

//>> GET_[ERROR_REG_INFO_ERROR]
static inline bool GET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> CLEAR_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_SEQ_ERROR]

//>> GET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_SEQ_ERROR]

//>> GET_[ERROR_REG_SEQ_ERROR]
static inline bool GET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> CLEAR_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline bool GET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> CLEAR_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline bool GET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> CLEAR_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[ERROR_REG_CHIPLET_OFFLINE]
static inline bool GET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> CLEAR_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline bool GET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PLL_UNLOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PLL_UNLOCK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> GET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PLL_UNLOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> CLEAR_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_FSM_ERROR]

//>> GET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_FSM_ERROR]

//>> GET_[ERROR_REG_QME_FSM_ERROR]
static inline bool GET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_FSM_ERROR]

//>> SET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> CLEAR_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline bool GET_ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> CLEAR_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline bool GET_ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
