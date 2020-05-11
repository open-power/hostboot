/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00021.H $          */
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

#ifndef __OMI_REG00021_H_
#define __OMI_REG00021_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[STATUS]

//>> GET_[STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_STATUS(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = STATUS;
#endif
    return fapi2::getScom(i_target, STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[STATUS]

//>> PUT_[STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return fapi2::putScom(i_target, STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[STATUS]


//>> SET_[STATUS_TRAINED_MODE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TRAINED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_TRAINED_MODE,
           STATUS_TRAINED_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_TRAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TRAINED_MODE]

//>> SET_[STATUS_TRAINED_MODE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TRAINED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_TRAINED_MODE,
           STATUS_TRAINED_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_TRAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TRAINED_MODE]

//>> GET_[STATUS_TRAINED_MODE]
static inline fapi2::buffer<uint64_t>& GET_STATUS_TRAINED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_TRAINED_MODE,
           STATUS_TRAINED_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_TRAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_TRAINED_MODE]

//>> SET_[STATUS_RX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RX_LANE_REVERSED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RX_LANE_REVERSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_RX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RX_LANE_REVERSED]

//>> SET_[STATUS_RX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RX_LANE_REVERSED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RX_LANE_REVERSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_RX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RX_LANE_REVERSED]

//>> SET_[STATUS_RX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RX_LANE_REVERSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.setBit<STATUS_RX_LANE_REVERSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access STATUS_RX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RX_LANE_REVERSED]

//>> CLEAR_[STATUS_RX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& CLEAR_STATUS_RX_LANE_REVERSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.clearBit<STATUS_RX_LANE_REVERSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access STATUS_RX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[STATUS_RX_LANE_REVERSED]

//>> GET_[STATUS_RX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& GET_STATUS_RX_LANE_REVERSED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_RX_LANE_REVERSED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_RX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_RX_LANE_REVERSED]

//>> GET_[STATUS_RX_LANE_REVERSED]
static inline bool GET_STATUS_RX_LANE_REVERSED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.getBit<STATUS_RX_LANE_REVERSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access STATUS_RX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_RX_LANE_REVERSED]

//>> SET_[STATUS_TX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TX_LANE_REVERSED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_TX_LANE_REVERSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_TX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TX_LANE_REVERSED]

//>> SET_[STATUS_TX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TX_LANE_REVERSED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_TX_LANE_REVERSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_TX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TX_LANE_REVERSED]

//>> SET_[STATUS_TX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TX_LANE_REVERSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.setBit<STATUS_TX_LANE_REVERSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access STATUS_TX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TX_LANE_REVERSED]

//>> CLEAR_[STATUS_TX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& CLEAR_STATUS_TX_LANE_REVERSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.clearBit<STATUS_TX_LANE_REVERSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access STATUS_TX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[STATUS_TX_LANE_REVERSED]

//>> GET_[STATUS_TX_LANE_REVERSED]
static inline fapi2::buffer<uint64_t>& GET_STATUS_TX_LANE_REVERSED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_TX_LANE_REVERSED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_TX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_TX_LANE_REVERSED]

//>> GET_[STATUS_TX_LANE_REVERSED]
static inline bool GET_STATUS_TX_LANE_REVERSED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.getBit<STATUS_TX_LANE_REVERSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access STATUS_TX_LANE_REVERSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_TX_LANE_REVERSED]

//>> SET_[STATUS_IDLE_SIZE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_IDLE_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_IDLE_SIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_IDLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_IDLE_SIZE]

//>> SET_[STATUS_IDLE_SIZE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_IDLE_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_IDLE_SIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_IDLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_IDLE_SIZE]

//>> SET_[STATUS_IDLE_SIZE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_IDLE_SIZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.setBit<STATUS_IDLE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access STATUS_IDLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_IDLE_SIZE]

//>> CLEAR_[STATUS_IDLE_SIZE]
static inline fapi2::buffer<uint64_t>& CLEAR_STATUS_IDLE_SIZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.clearBit<STATUS_IDLE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access STATUS_IDLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[STATUS_IDLE_SIZE]

//>> GET_[STATUS_IDLE_SIZE]
static inline fapi2::buffer<uint64_t>& GET_STATUS_IDLE_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_IDLE_SIZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_IDLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_IDLE_SIZE]

//>> GET_[STATUS_IDLE_SIZE]
static inline bool GET_STATUS_IDLE_SIZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.getBit<STATUS_IDLE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access STATUS_IDLE_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_IDLE_SIZE]

//>> SET_[STATUS_ACK_PTRS_EQUAL]
static inline fapi2::buffer<uint64_t>& SET_STATUS_ACK_PTRS_EQUAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_ACK_PTRS_EQUAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_ACK_PTRS_EQUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_ACK_PTRS_EQUAL]

//>> SET_[STATUS_ACK_PTRS_EQUAL]
static inline fapi2::buffer<uint64_t>& SET_STATUS_ACK_PTRS_EQUAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_ACK_PTRS_EQUAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_ACK_PTRS_EQUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_ACK_PTRS_EQUAL]

//>> SET_[STATUS_ACK_PTRS_EQUAL]
static inline fapi2::buffer<uint64_t>& SET_STATUS_ACK_PTRS_EQUAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.setBit<STATUS_ACK_PTRS_EQUAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access STATUS_ACK_PTRS_EQUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_ACK_PTRS_EQUAL]

//>> CLEAR_[STATUS_ACK_PTRS_EQUAL]
static inline fapi2::buffer<uint64_t>& CLEAR_STATUS_ACK_PTRS_EQUAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.clearBit<STATUS_ACK_PTRS_EQUAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access STATUS_ACK_PTRS_EQUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[STATUS_ACK_PTRS_EQUAL]

//>> GET_[STATUS_ACK_PTRS_EQUAL]
static inline fapi2::buffer<uint64_t>& GET_STATUS_ACK_PTRS_EQUAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_ACK_PTRS_EQUAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_ACK_PTRS_EQUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_ACK_PTRS_EQUAL]

//>> GET_[STATUS_ACK_PTRS_EQUAL]
static inline bool GET_STATUS_ACK_PTRS_EQUAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.getBit<STATUS_ACK_PTRS_EQUAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access STATUS_ACK_PTRS_EQUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_ACK_PTRS_EQUAL]

//>> SET_[STATUS_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RSVD1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RSVD1,
           STATUS_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RSVD1]

//>> SET_[STATUS_RSVD1]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RSVD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RSVD1,
           STATUS_RSVD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RSVD1]

//>> GET_[STATUS_RSVD1]
static inline fapi2::buffer<uint64_t>& GET_STATUS_RSVD1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_RSVD1,
           STATUS_RSVD1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_RSVD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_RSVD1]

//>> SET_[STATUS_REQUESTED_LN_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_STATUS_REQUESTED_LN_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_REQUESTED_LN_WIDTH,
           STATUS_REQUESTED_LN_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_REQUESTED_LN_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_REQUESTED_LN_WIDTH]

//>> SET_[STATUS_REQUESTED_LN_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_STATUS_REQUESTED_LN_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_REQUESTED_LN_WIDTH,
           STATUS_REQUESTED_LN_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_REQUESTED_LN_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_REQUESTED_LN_WIDTH]

//>> GET_[STATUS_REQUESTED_LN_WIDTH]
static inline fapi2::buffer<uint64_t>& GET_STATUS_REQUESTED_LN_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_REQUESTED_LN_WIDTH,
           STATUS_REQUESTED_LN_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_REQUESTED_LN_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_REQUESTED_LN_WIDTH]

//>> SET_[STATUS_ACTUAL_LN_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_STATUS_ACTUAL_LN_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_ACTUAL_LN_WIDTH,
           STATUS_ACTUAL_LN_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_ACTUAL_LN_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_ACTUAL_LN_WIDTH]

//>> SET_[STATUS_ACTUAL_LN_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_STATUS_ACTUAL_LN_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_ACTUAL_LN_WIDTH,
           STATUS_ACTUAL_LN_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_ACTUAL_LN_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_ACTUAL_LN_WIDTH]

//>> GET_[STATUS_ACTUAL_LN_WIDTH]
static inline fapi2::buffer<uint64_t>& GET_STATUS_ACTUAL_LN_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_ACTUAL_LN_WIDTH,
           STATUS_ACTUAL_LN_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_ACTUAL_LN_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_ACTUAL_LN_WIDTH]

//>> SET_[STATUS_TX_TRAINED_LANES]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TX_TRAINED_LANES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_TX_TRAINED_LANES,
           STATUS_TX_TRAINED_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_TX_TRAINED_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TX_TRAINED_LANES]

//>> SET_[STATUS_TX_TRAINED_LANES]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TX_TRAINED_LANES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_TX_TRAINED_LANES,
           STATUS_TX_TRAINED_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_TX_TRAINED_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TX_TRAINED_LANES]

//>> GET_[STATUS_TX_TRAINED_LANES]
static inline fapi2::buffer<uint64_t>& GET_STATUS_TX_TRAINED_LANES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_TX_TRAINED_LANES,
           STATUS_TX_TRAINED_LANES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_TX_TRAINED_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_TX_TRAINED_LANES]

//>> SET_[STATUS_RX_TRAINED_LANES]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RX_TRAINED_LANES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RX_TRAINED_LANES,
           STATUS_RX_TRAINED_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_RX_TRAINED_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RX_TRAINED_LANES]

//>> SET_[STATUS_RX_TRAINED_LANES]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RX_TRAINED_LANES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RX_TRAINED_LANES,
           STATUS_RX_TRAINED_LANES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_RX_TRAINED_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RX_TRAINED_LANES]

//>> GET_[STATUS_RX_TRAINED_LANES]
static inline fapi2::buffer<uint64_t>& GET_STATUS_RX_TRAINED_LANES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_RX_TRAINED_LANES,
           STATUS_RX_TRAINED_LANES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_RX_TRAINED_LANES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_RX_TRAINED_LANES]

//>> SET_[STATUS_ENDPOINT_INFO]
static inline fapi2::buffer<uint64_t>& SET_STATUS_ENDPOINT_INFO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_ENDPOINT_INFO,
           STATUS_ENDPOINT_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_ENDPOINT_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_ENDPOINT_INFO]

//>> SET_[STATUS_ENDPOINT_INFO]
static inline fapi2::buffer<uint64_t>& SET_STATUS_ENDPOINT_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_ENDPOINT_INFO,
           STATUS_ENDPOINT_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_ENDPOINT_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_ENDPOINT_INFO]

//>> GET_[STATUS_ENDPOINT_INFO]
static inline fapi2::buffer<uint64_t>& GET_STATUS_ENDPOINT_INFO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_ENDPOINT_INFO,
           STATUS_ENDPOINT_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_ENDPOINT_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_ENDPOINT_INFO]

//>> SET_[STATUS_PM_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_PM_DISABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_PM_DISABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_PM_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_PM_DISABLED]

//>> SET_[STATUS_PM_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_PM_DISABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_PM_DISABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_PM_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_PM_DISABLED]

//>> SET_[STATUS_PM_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_PM_DISABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.setBit<STATUS_PM_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access STATUS_PM_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_PM_DISABLED]

//>> CLEAR_[STATUS_PM_DISABLED]
static inline fapi2::buffer<uint64_t>& CLEAR_STATUS_PM_DISABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.clearBit<STATUS_PM_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access STATUS_PM_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[STATUS_PM_DISABLED]

//>> GET_[STATUS_PM_DISABLED]
static inline fapi2::buffer<uint64_t>& GET_STATUS_PM_DISABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_PM_DISABLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_PM_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_PM_DISABLED]

//>> GET_[STATUS_PM_DISABLED]
static inline bool GET_STATUS_PM_DISABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.getBit<STATUS_PM_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access STATUS_PM_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_PM_DISABLED]

//>> SET_[STATUS_RSVD2]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RSVD2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RSVD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RSVD2]

//>> SET_[STATUS_RSVD2]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RSVD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RSVD2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RSVD2]

//>> SET_[STATUS_RSVD2]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RSVD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.setBit<STATUS_RSVD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access STATUS_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RSVD2]

//>> CLEAR_[STATUS_RSVD2]
static inline fapi2::buffer<uint64_t>& CLEAR_STATUS_RSVD2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.clearBit<STATUS_RSVD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access STATUS_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[STATUS_RSVD2]

//>> GET_[STATUS_RSVD2]
static inline fapi2::buffer<uint64_t>& GET_STATUS_RSVD2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_RSVD2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_RSVD2]

//>> GET_[STATUS_RSVD2]
static inline bool GET_STATUS_RSVD2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.getBit<STATUS_RSVD2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access STATUS_RSVD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_RSVD2]

//>> SET_[STATUS_TRAINING_STATE_MACHINE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TRAINING_STATE_MACHINE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_TRAINING_STATE_MACHINE,
           STATUS_TRAINING_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_TRAINING_STATE_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TRAINING_STATE_MACHINE]

//>> SET_[STATUS_TRAINING_STATE_MACHINE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_TRAINING_STATE_MACHINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_TRAINING_STATE_MACHINE,
           STATUS_TRAINING_STATE_MACHINE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_TRAINING_STATE_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_TRAINING_STATE_MACHINE]

//>> GET_[STATUS_TRAINING_STATE_MACHINE]
static inline fapi2::buffer<uint64_t>& GET_STATUS_TRAINING_STATE_MACHINE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_TRAINING_STATE_MACHINE,
           STATUS_TRAINING_STATE_MACHINE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_TRAINING_STATE_MACHINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_TRAINING_STATE_MACHINE]

//>> SET_[STATUS_RSVD3]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RSVD3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RSVD3,
           STATUS_RSVD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RSVD3]

//>> SET_[STATUS_RSVD3]
static inline fapi2::buffer<uint64_t>& SET_STATUS_RSVD3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_RSVD3,
           STATUS_RSVD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_RSVD3]

//>> GET_[STATUS_RSVD3]
static inline fapi2::buffer<uint64_t>& GET_STATUS_RSVD3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_RSVD3,
           STATUS_RSVD3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_RSVD3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_RSVD3]

//>> SET_[STATUS_DESKEW_DONE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_DESKEW_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_DESKEW_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_DESKEW_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_DESKEW_DONE]

//>> SET_[STATUS_DESKEW_DONE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_DESKEW_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_DESKEW_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_DESKEW_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_DESKEW_DONE]

//>> SET_[STATUS_DESKEW_DONE]
static inline fapi2::buffer<uint64_t>& SET_STATUS_DESKEW_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.setBit<STATUS_DESKEW_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access STATUS_DESKEW_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_DESKEW_DONE]

//>> CLEAR_[STATUS_DESKEW_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_STATUS_DESKEW_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.clearBit<STATUS_DESKEW_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access STATUS_DESKEW_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[STATUS_DESKEW_DONE]

//>> GET_[STATUS_DESKEW_DONE]
static inline fapi2::buffer<uint64_t>& GET_STATUS_DESKEW_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_DESKEW_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_DESKEW_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_DESKEW_DONE]

//>> GET_[STATUS_DESKEW_DONE]
static inline bool GET_STATUS_DESKEW_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.getBit<STATUS_DESKEW_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access STATUS_DESKEW_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_DESKEW_DONE]

//>> SET_[STATUS_LANES_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_LANES_DISABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_LANES_DISABLED,
           STATUS_LANES_DISABLED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access STATUS_LANES_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_LANES_DISABLED]

//>> SET_[STATUS_LANES_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_STATUS_LANES_DISABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return o_data.insertFromRight<STATUS_LANES_DISABLED,
           STATUS_LANES_DISABLED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access STATUS_LANES_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[STATUS_LANES_DISABLED]

//>> GET_[STATUS_LANES_DISABLED]
static inline fapi2::buffer<uint64_t>& GET_STATUS_LANES_DISABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(STATUS));
#endif
    return i_data.extractToRight<STATUS_LANES_DISABLED,
           STATUS_LANES_DISABLED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access STATUS_LANES_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[STATUS_LANES_DISABLED]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
