/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00065.H $         */
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

#ifndef __IOHS_REG00065_H_
#define __IOHS_REG00065_H_

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

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK0_ERROR_STATUS_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
