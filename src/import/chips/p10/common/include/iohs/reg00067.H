/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00067.H $         */
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

#ifndef __IOHS_REG00067_H_
#define __IOHS_REG00067_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_DLL_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_DLL_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_DLL_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_DLL_STATUS]

//>> GET_[DLP_DLL_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_DLL_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_DLL_STATUS;
#endif
    return fapi2::getScom(i_target, DLP_DLL_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_DLL_STATUS]

//>> PUT_[DLP_DLL_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_DLL_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return fapi2::putScom(i_target, DLP_DLL_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_DLL_STATUS]


//>> SET_[DLP_DLL_STATUS_0_PHY_TRAINING_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PHY_TRAINING_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_0_PHY_TRAINING_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_PHY_TRAINING_STATE]

//>> SET_[DLP_DLL_STATUS_0_PHY_TRAINING_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PHY_TRAINING_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_0_PHY_TRAINING_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_PHY_TRAINING_STATE]

//>> GET_[DLP_DLL_STATUS_0_PHY_TRAINING_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_PHY_TRAINING_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_0_PHY_TRAINING_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_PHY_TRAINING_STATE]

//>> SET_[DLP_DLL_STATUS_0_CURRENT_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_CURRENT_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_CURRENT_STATE,
           DLP_DLL_STATUS_0_CURRENT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_CURRENT_STATE]

//>> SET_[DLP_DLL_STATUS_0_CURRENT_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_CURRENT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_CURRENT_STATE,
           DLP_DLL_STATUS_0_CURRENT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_CURRENT_STATE]

//>> GET_[DLP_DLL_STATUS_0_CURRENT_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_CURRENT_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_CURRENT_STATE,
           DLP_DLL_STATUS_0_CURRENT_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_CURRENT_STATE]

//>> SET_[DLP_DLL_STATUS_0_TIMEOUT_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TIMEOUT_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TIMEOUT_STATE,
           DLP_DLL_STATUS_0_TIMEOUT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_TIMEOUT_STATE]

//>> SET_[DLP_DLL_STATUS_0_TIMEOUT_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TIMEOUT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TIMEOUT_STATE,
           DLP_DLL_STATUS_0_TIMEOUT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_TIMEOUT_STATE]

//>> GET_[DLP_DLL_STATUS_0_TIMEOUT_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_TIMEOUT_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_TIMEOUT_STATE,
           DLP_DLL_STATUS_0_TIMEOUT_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_TIMEOUT_STATE]

//>> SET_[DLP_DLL_STATUS_0_PRIOR_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PRIOR_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PRIOR_STATE,
           DLP_DLL_STATUS_0_PRIOR_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_PRIOR_STATE]

//>> SET_[DLP_DLL_STATUS_0_PRIOR_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PRIOR_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PRIOR_STATE,
           DLP_DLL_STATUS_0_PRIOR_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_PRIOR_STATE]

//>> GET_[DLP_DLL_STATUS_0_PRIOR_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_PRIOR_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_PRIOR_STATE,
           DLP_DLL_STATUS_0_PRIOR_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_PRIOR_STATE]

//>> SET_[DLP_DLL_STATUS_0_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_OPTICS_RST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_OPTICS_RST_B]

//>> SET_[DLP_DLL_STATUS_0_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_RST_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_OPTICS_RST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_OPTICS_RST_B]

//>> SET_[DLP_DLL_STATUS_0_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_OPTICS_RST_B]

//>> CLEAR_[DLP_DLL_STATUS_0_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_0_OPTICS_RST_B]

//>> GET_[DLP_DLL_STATUS_0_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_OPTICS_RST_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_OPTICS_RST_B]

//>> GET_[DLP_DLL_STATUS_0_OPTICS_RST_B]
static inline bool GET_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_OPTICS_RST_B]

//>> SET_[DLP_DLL_STATUS_0_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_OPTICS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_OPTICS_IRQ]

//>> SET_[DLP_DLL_STATUS_0_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_IRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_OPTICS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_OPTICS_IRQ]

//>> SET_[DLP_DLL_STATUS_0_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_OPTICS_IRQ]

//>> CLEAR_[DLP_DLL_STATUS_0_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_0_OPTICS_IRQ]

//>> GET_[DLP_DLL_STATUS_0_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_OPTICS_IRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_OPTICS_IRQ]

//>> GET_[DLP_DLL_STATUS_0_OPTICS_IRQ]
static inline bool GET_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_OPTICS_IRQ]

//>> SET_[DLP_DLL_STATUS_0_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_TRAINING]

//>> SET_[DLP_DLL_STATUS_0_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TRAINING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_TRAINING]

//>> SET_[DLP_DLL_STATUS_0_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_TRAINING]

//>> CLEAR_[DLP_DLL_STATUS_0_TRAINING]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_0_TRAINING]

//>> GET_[DLP_DLL_STATUS_0_TRAINING]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_TRAINING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_TRAINING]

//>> GET_[DLP_DLL_STATUS_0_TRAINING]
static inline bool GET_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_TRAINING]

//>> SET_[DLP_DLL_STATUS_0_MAX_PKT_TIMER]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_MAX_PKT_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_MAX_PKT_TIMER,
           DLP_DLL_STATUS_0_MAX_PKT_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_MAX_PKT_TIMER]

//>> SET_[DLP_DLL_STATUS_0_MAX_PKT_TIMER]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_MAX_PKT_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_MAX_PKT_TIMER,
           DLP_DLL_STATUS_0_MAX_PKT_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_MAX_PKT_TIMER]

//>> GET_[DLP_DLL_STATUS_0_MAX_PKT_TIMER]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_MAX_PKT_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_MAX_PKT_TIMER,
           DLP_DLL_STATUS_0_MAX_PKT_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_MAX_PKT_TIMER]

//>> SET_[DLP_DLL_STATUS_1_PHY_TRAINING_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PHY_TRAINING_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_1_PHY_TRAINING_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_PHY_TRAINING_STATE]

//>> SET_[DLP_DLL_STATUS_1_PHY_TRAINING_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PHY_TRAINING_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_1_PHY_TRAINING_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_PHY_TRAINING_STATE]

//>> GET_[DLP_DLL_STATUS_1_PHY_TRAINING_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_PHY_TRAINING_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_1_PHY_TRAINING_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_PHY_TRAINING_STATE]

//>> SET_[DLP_DLL_STATUS_1_CURRENT_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_CURRENT_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_CURRENT_STATE,
           DLP_DLL_STATUS_1_CURRENT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_CURRENT_STATE]

//>> SET_[DLP_DLL_STATUS_1_CURRENT_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_CURRENT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_CURRENT_STATE,
           DLP_DLL_STATUS_1_CURRENT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_CURRENT_STATE]

//>> GET_[DLP_DLL_STATUS_1_CURRENT_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_CURRENT_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_CURRENT_STATE,
           DLP_DLL_STATUS_1_CURRENT_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_CURRENT_STATE]

//>> SET_[DLP_DLL_STATUS_1_TIMEOUT_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TIMEOUT_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TIMEOUT_STATE,
           DLP_DLL_STATUS_1_TIMEOUT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_TIMEOUT_STATE]

//>> SET_[DLP_DLL_STATUS_1_TIMEOUT_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TIMEOUT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TIMEOUT_STATE,
           DLP_DLL_STATUS_1_TIMEOUT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_TIMEOUT_STATE]

//>> GET_[DLP_DLL_STATUS_1_TIMEOUT_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_TIMEOUT_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_TIMEOUT_STATE,
           DLP_DLL_STATUS_1_TIMEOUT_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_TIMEOUT_STATE]

//>> SET_[DLP_DLL_STATUS_1_PRIOR_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PRIOR_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PRIOR_STATE,
           DLP_DLL_STATUS_1_PRIOR_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_PRIOR_STATE]

//>> SET_[DLP_DLL_STATUS_1_PRIOR_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PRIOR_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PRIOR_STATE,
           DLP_DLL_STATUS_1_PRIOR_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_PRIOR_STATE]

//>> GET_[DLP_DLL_STATUS_1_PRIOR_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_PRIOR_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_PRIOR_STATE,
           DLP_DLL_STATUS_1_PRIOR_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_PRIOR_STATE]

//>> SET_[DLP_DLL_STATUS_1_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_OPTICS_RST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_OPTICS_RST_B]

//>> SET_[DLP_DLL_STATUS_1_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_RST_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_OPTICS_RST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_OPTICS_RST_B]

//>> SET_[DLP_DLL_STATUS_1_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_OPTICS_RST_B]

//>> CLEAR_[DLP_DLL_STATUS_1_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_1_OPTICS_RST_B]

//>> GET_[DLP_DLL_STATUS_1_OPTICS_RST_B]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_OPTICS_RST_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_OPTICS_RST_B]

//>> GET_[DLP_DLL_STATUS_1_OPTICS_RST_B]
static inline bool GET_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_OPTICS_RST_B]

//>> SET_[DLP_DLL_STATUS_1_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_OPTICS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_OPTICS_IRQ]

//>> SET_[DLP_DLL_STATUS_1_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_IRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_OPTICS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_OPTICS_IRQ]

//>> SET_[DLP_DLL_STATUS_1_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_OPTICS_IRQ]

//>> CLEAR_[DLP_DLL_STATUS_1_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_1_OPTICS_IRQ]

//>> GET_[DLP_DLL_STATUS_1_OPTICS_IRQ]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_OPTICS_IRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_OPTICS_IRQ]

//>> GET_[DLP_DLL_STATUS_1_OPTICS_IRQ]
static inline bool GET_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_OPTICS_IRQ]

//>> SET_[DLP_DLL_STATUS_1_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_TRAINING]

//>> SET_[DLP_DLL_STATUS_1_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TRAINING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_TRAINING]

//>> SET_[DLP_DLL_STATUS_1_TRAINING]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_TRAINING]

//>> CLEAR_[DLP_DLL_STATUS_1_TRAINING]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_1_TRAINING]

//>> GET_[DLP_DLL_STATUS_1_TRAINING]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_TRAINING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_TRAINING]

//>> GET_[DLP_DLL_STATUS_1_TRAINING]
static inline bool GET_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_TRAINING]

//>> SET_[DLP_DLL_STATUS_1_MAX_PKT_TIMER]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_MAX_PKT_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_MAX_PKT_TIMER,
           DLP_DLL_STATUS_1_MAX_PKT_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_MAX_PKT_TIMER]

//>> SET_[DLP_DLL_STATUS_1_MAX_PKT_TIMER]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_MAX_PKT_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_MAX_PKT_TIMER,
           DLP_DLL_STATUS_1_MAX_PKT_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_MAX_PKT_TIMER]

//>> GET_[DLP_DLL_STATUS_1_MAX_PKT_TIMER]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_MAX_PKT_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_MAX_PKT_TIMER,
           DLP_DLL_STATUS_1_MAX_PKT_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_MAX_PKT_TIMER]

//>> SET_[DLP_DLL_STATUS_0_LINK_UP]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_LINK_UP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_LINK_UP]

//>> SET_[DLP_DLL_STATUS_0_LINK_UP]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_LINK_UP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_LINK_UP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_LINK_UP]

//>> SET_[DLP_DLL_STATUS_0_LINK_UP]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_LINK_UP]

//>> CLEAR_[DLP_DLL_STATUS_0_LINK_UP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_0_LINK_UP]

//>> GET_[DLP_DLL_STATUS_0_LINK_UP]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_LINK_UP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_LINK_UP]

//>> GET_[DLP_DLL_STATUS_0_LINK_UP]
static inline bool GET_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_LINK_UP]

//>> SET_[DLP_DLL_STATUS_1_LINK_UP]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_LINK_UP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_LINK_UP]

//>> SET_[DLP_DLL_STATUS_1_LINK_UP]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_LINK_UP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_LINK_UP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_LINK_UP]

//>> SET_[DLP_DLL_STATUS_1_LINK_UP]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_LINK_UP]

//>> CLEAR_[DLP_DLL_STATUS_1_LINK_UP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_1_LINK_UP]

//>> GET_[DLP_DLL_STATUS_1_LINK_UP]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_LINK_UP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_LINK_UP]

//>> GET_[DLP_DLL_STATUS_1_LINK_UP]
static inline bool GET_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_LINK_UP]

//>> SET_[DLP_DLL_STATUS_0_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_RESET_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_RESET_ACTIVE]

//>> SET_[DLP_DLL_STATUS_0_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_RESET_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_RESET_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_RESET_ACTIVE]

//>> SET_[DLP_DLL_STATUS_0_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_RESET_ACTIVE]

//>> CLEAR_[DLP_DLL_STATUS_0_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_0_RESET_ACTIVE]

//>> GET_[DLP_DLL_STATUS_0_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_RESET_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_RESET_ACTIVE]

//>> GET_[DLP_DLL_STATUS_0_RESET_ACTIVE]
static inline bool GET_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_RESET_ACTIVE]

//>> SET_[DLP_DLL_STATUS_1_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_RESET_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_RESET_ACTIVE]

//>> SET_[DLP_DLL_STATUS_1_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_RESET_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_RESET_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_RESET_ACTIVE]

//>> SET_[DLP_DLL_STATUS_1_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_RESET_ACTIVE]

//>> CLEAR_[DLP_DLL_STATUS_1_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_DLL_STATUS_1_RESET_ACTIVE]

//>> GET_[DLP_DLL_STATUS_1_RESET_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_RESET_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_RESET_ACTIVE]

//>> GET_[DLP_DLL_STATUS_1_RESET_ACTIVE]
static inline bool GET_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_RESET_ACTIVE]

//>> SET_[DLP_DLL_STATUS_0_TDM_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TDM_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TDM_STATUS,
           DLP_DLL_STATUS_0_TDM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_TDM_STATUS]

//>> SET_[DLP_DLL_STATUS_0_TDM_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TDM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TDM_STATUS,
           DLP_DLL_STATUS_0_TDM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_TDM_STATUS]

//>> GET_[DLP_DLL_STATUS_0_TDM_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_TDM_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_TDM_STATUS,
           DLP_DLL_STATUS_0_TDM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_TDM_STATUS]

//>> SET_[DLP_DLL_STATUS_1_TDM_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TDM_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TDM_STATUS,
           DLP_DLL_STATUS_1_TDM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_TDM_STATUS]

//>> SET_[DLP_DLL_STATUS_1_TDM_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TDM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TDM_STATUS,
           DLP_DLL_STATUS_1_TDM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_TDM_STATUS]

//>> GET_[DLP_DLL_STATUS_1_TDM_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_TDM_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_TDM_STATUS,
           DLP_DLL_STATUS_1_TDM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_TDM_STATUS]

//>> SET_[DLP_DLL_STATUS_0_PSAVE_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PSAVE_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PSAVE_STATE,
           DLP_DLL_STATUS_0_PSAVE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_PSAVE_STATE]

//>> SET_[DLP_DLL_STATUS_0_PSAVE_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PSAVE_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PSAVE_STATE,
           DLP_DLL_STATUS_0_PSAVE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_0_PSAVE_STATE]

//>> GET_[DLP_DLL_STATUS_0_PSAVE_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_PSAVE_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_PSAVE_STATE,
           DLP_DLL_STATUS_0_PSAVE_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_0_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_0_PSAVE_STATE]

//>> SET_[DLP_DLL_STATUS_1_PSAVE_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PSAVE_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PSAVE_STATE,
           DLP_DLL_STATUS_1_PSAVE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_PSAVE_STATE]

//>> SET_[DLP_DLL_STATUS_1_PSAVE_STATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PSAVE_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PSAVE_STATE,
           DLP_DLL_STATUS_1_PSAVE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_DLL_STATUS_1_PSAVE_STATE]

//>> GET_[DLP_DLL_STATUS_1_PSAVE_STATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_PSAVE_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_PSAVE_STATE,
           DLP_DLL_STATUS_1_PSAVE_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_DLL_STATUS_1_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_DLL_STATUS_1_PSAVE_STATE]

//>> PREP_[DLP_LINK0_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_ERROR_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK0_ERROR_STATUS]

//>> GET_[DLP_LINK0_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_ERROR_STATUS;
#endif
    return fapi2::getScom(i_target, DLP_LINK0_ERROR_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS]

//>> PUT_[DLP_LINK0_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return fapi2::putScom(i_target, DLP_LINK0_ERROR_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK0_ERROR_STATUS]


//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]
static inline bool GET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER]

//>> SET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]

//>> SET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]

//>> SET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]

//>> GET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]

//>> GET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RESET_KEEPER]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]
static inline bool GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline bool GET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]
static inline bool GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline bool GET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC]

//>> SET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]

//>> GET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]

//>> GET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]
static inline bool GET_DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> GET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> GET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN]

//>> SET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]

//>> SET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]

//>> SET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]

//>> GET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]

//>> GET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]
static inline bool GET_DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN]

//>> SET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]

//>> SET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]

//>> SET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]

//>> GET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]

//>> GET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]
static inline bool GET_DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP]

//>> SET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LANE_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LANE_MISMATCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LANE_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_LANE_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_LANE_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]

//>> GET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LANE_MISMATCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]

//>> GET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]
static inline bool GET_DLP_LINK0_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_LANE_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LANE_MISMATCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK_MISMATCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_LINK_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_LINK_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK_MISMATCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]
static inline bool GET_DLP_LINK0_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_LINK_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK_MISMATCH]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RX_SLOWER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_SLOWER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RX_SLOWER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RX_SLOWER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RX_SLOWER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]

//>> GET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RX_SLOWER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]

//>> GET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RX_SLOWER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RX_SLOWER]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline bool GET_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline bool GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]

//>> SET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]

//>> SET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]

//>> GET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]

//>> GET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]
static inline bool GET_DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline bool GET_DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]
static inline bool GET_DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_REMOTE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_REMOTE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_REMOTE_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]
static inline bool GET_DLP_LINK0_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_REMOTE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_UE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> SET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> GET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline bool GET_DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_INTERNAL,
           DLP_LINK0_ERROR_STATUS_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_INTERNAL]

//>> SET_[DLP_LINK0_ERROR_STATUS_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_INTERNAL,
           DLP_LINK0_ERROR_STATUS_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_INTERNAL]

//>> GET_[DLP_LINK0_ERROR_STATUS_INTERNAL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_INTERNAL,
           DLP_LINK0_ERROR_STATUS_INTERNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_INTERNAL]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline bool GET_DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> CLEAR_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline bool GET_DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
