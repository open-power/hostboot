/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00000.H $         */
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

#ifndef __IOHS_REG00000_H_
#define __IOHS_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_LINK1_INFO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK1_INFO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_INFO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK1_INFO]

//>> GET_[DLP_LINK1_INFO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK1_INFO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_INFO;
#endif
    return fapi2::getScom(i_target, DLP_LINK1_INFO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK1_INFO]

//>> PUT_[DLP_LINK1_INFO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK1_INFO(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return fapi2::putScom(i_target, DLP_LINK1_INFO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK1_INFO]


//>> SET_[DLP_LINK1_INFO_MAX_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_MAX_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_MAX_TIMEOUT,
           DLP_LINK1_INFO_MAX_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_MAX_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_MAX_TIMEOUT]

//>> SET_[DLP_LINK1_INFO_MAX_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_MAX_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_MAX_TIMEOUT,
           DLP_LINK1_INFO_MAX_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_MAX_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_MAX_TIMEOUT]

//>> GET_[DLP_LINK1_INFO_MAX_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_MAX_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_MAX_TIMEOUT,
           DLP_LINK1_INFO_MAX_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_MAX_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_MAX_TIMEOUT]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_FRAME_CAP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_FRAME_CAP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.setBit<DLP_LINK1_INFO_FRAME_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_VALID]

//>> CLEAR_[DLP_LINK1_INFO_FRAME_CAP_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK1_INFO_FRAME_CAP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.clearBit<DLP_LINK1_INFO_FRAME_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK1_INFO_FRAME_CAP_VALID]

//>> GET_[DLP_LINK1_INFO_FRAME_CAP_VALID]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_FRAME_CAP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_FRAME_CAP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_FRAME_CAP_VALID]

//>> GET_[DLP_LINK1_INFO_FRAME_CAP_VALID]
static inline bool GET_DLP_LINK1_INFO_FRAME_CAP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.getBit<DLP_LINK1_INFO_FRAME_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_FRAME_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_INST]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_INST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_FRAME_CAP_INST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_INST]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_INST]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_INST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_FRAME_CAP_INST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_INST]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_INST]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_INST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.setBit<DLP_LINK1_INFO_FRAME_CAP_INST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_INST]

//>> CLEAR_[DLP_LINK1_INFO_FRAME_CAP_INST]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK1_INFO_FRAME_CAP_INST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.clearBit<DLP_LINK1_INFO_FRAME_CAP_INST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK1_INFO_FRAME_CAP_INST]

//>> GET_[DLP_LINK1_INFO_FRAME_CAP_INST]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_FRAME_CAP_INST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_FRAME_CAP_INST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_FRAME_CAP_INST]

//>> GET_[DLP_LINK1_INFO_FRAME_CAP_INST]
static inline bool GET_DLP_LINK1_INFO_FRAME_CAP_INST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.getBit<DLP_LINK1_INFO_FRAME_CAP_INST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_FRAME_CAP_INST]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_FRAME_CAP_ADDR,
           DLP_LINK1_INFO_FRAME_CAP_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_ADDR]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_FRAME_CAP_ADDR,
           DLP_LINK1_INFO_FRAME_CAP_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_ADDR]

//>> GET_[DLP_LINK1_INFO_FRAME_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_FRAME_CAP_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_FRAME_CAP_ADDR,
           DLP_LINK1_INFO_FRAME_CAP_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_FRAME_CAP_ADDR]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_SYN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_SYN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_FRAME_CAP_SYN,
           DLP_LINK1_INFO_FRAME_CAP_SYN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_SYN]

//>> SET_[DLP_LINK1_INFO_FRAME_CAP_SYN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_FRAME_CAP_SYN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_FRAME_CAP_SYN,
           DLP_LINK1_INFO_FRAME_CAP_SYN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_FRAME_CAP_SYN]

//>> GET_[DLP_LINK1_INFO_FRAME_CAP_SYN]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_FRAME_CAP_SYN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_FRAME_CAP_SYN,
           DLP_LINK1_INFO_FRAME_CAP_SYN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_FRAME_CAP_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_FRAME_CAP_SYN]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_REPLAY_CAP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_REPLAY_CAP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.setBit<DLP_LINK1_INFO_REPLAY_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]

//>> CLEAR_[DLP_LINK1_INFO_REPLAY_CAP_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK1_INFO_REPLAY_CAP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.clearBit<DLP_LINK1_INFO_REPLAY_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK1_INFO_REPLAY_CAP_VALID]

//>> GET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_REPLAY_CAP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_REPLAY_CAP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]

//>> GET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]
static inline bool GET_DLP_LINK1_INFO_REPLAY_CAP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.getBit<DLP_LINK1_INFO_REPLAY_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_REPLAY_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_INST]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_INST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_REPLAY_CAP_INST,
           DLP_LINK1_INFO_REPLAY_CAP_INST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_INST]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_INST]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_INST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_REPLAY_CAP_INST,
           DLP_LINK1_INFO_REPLAY_CAP_INST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_INST]

//>> GET_[DLP_LINK1_INFO_REPLAY_CAP_INST]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_REPLAY_CAP_INST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_REPLAY_CAP_INST,
           DLP_LINK1_INFO_REPLAY_CAP_INST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_INST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_REPLAY_CAP_INST]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_REPLAY_CAP_ADDR,
           DLP_LINK1_INFO_REPLAY_CAP_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_ADDR]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_REPLAY_CAP_ADDR,
           DLP_LINK1_INFO_REPLAY_CAP_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_ADDR]

//>> GET_[DLP_LINK1_INFO_REPLAY_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_REPLAY_CAP_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_REPLAY_CAP_ADDR,
           DLP_LINK1_INFO_REPLAY_CAP_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_REPLAY_CAP_ADDR]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_SYN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_SYN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_REPLAY_CAP_SYN,
           DLP_LINK1_INFO_REPLAY_CAP_SYN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_SYN]

//>> SET_[DLP_LINK1_INFO_REPLAY_CAP_SYN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_REPLAY_CAP_SYN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_REPLAY_CAP_SYN,
           DLP_LINK1_INFO_REPLAY_CAP_SYN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_REPLAY_CAP_SYN]

//>> GET_[DLP_LINK1_INFO_REPLAY_CAP_SYN]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_REPLAY_CAP_SYN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_REPLAY_CAP_SYN,
           DLP_LINK1_INFO_REPLAY_CAP_SYN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_REPLAY_CAP_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_REPLAY_CAP_SYN]

//>> SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_ACK_FIFO_CAP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_ACK_FIFO_CAP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_ACK_FIFO_CAP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_ACK_FIFO_CAP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_ACK_FIFO_CAP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.setBit<DLP_LINK1_INFO_ACK_FIFO_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]

//>> CLEAR_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK1_INFO_ACK_FIFO_CAP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.clearBit<DLP_LINK1_INFO_ACK_FIFO_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]

//>> GET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_ACK_FIFO_CAP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_ACK_FIFO_CAP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]

//>> GET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]
static inline bool GET_DLP_LINK1_INFO_ACK_FIFO_CAP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.getBit<DLP_LINK1_INFO_ACK_FIFO_CAP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_ACK_FIFO_CAP_VALID]

//>> SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR,
           DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR]

//>> SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return o_data.insertFromRight<DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR,
           DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR]

//>> GET_[DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_INFO));
#endif
    return i_data.extractToRight<DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR,
           DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR]

//>> PREP_[DLP_LINK0_SYN_CAPTURE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK0_SYN_CAPTURE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_SYN_CAPTURE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK0_SYN_CAPTURE]

//>> GET_[DLP_LINK0_SYN_CAPTURE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK0_SYN_CAPTURE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_SYN_CAPTURE;
#endif
    return fapi2::getScom(i_target, DLP_LINK0_SYN_CAPTURE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK0_SYN_CAPTURE]

//>> PUT_[DLP_LINK0_SYN_CAPTURE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK0_SYN_CAPTURE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return fapi2::putScom(i_target, DLP_LINK0_SYN_CAPTURE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK0_SYN_CAPTURE]


//>> SET_[DLP_LINK0_SYN_CAPTURE_CRC_SYN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_CRC_SYN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_CRC_SYN,
           DLP_LINK0_SYN_CAPTURE_CRC_SYN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_CRC_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_CRC_SYN]

//>> SET_[DLP_LINK0_SYN_CAPTURE_CRC_SYN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_CRC_SYN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_CRC_SYN,
           DLP_LINK0_SYN_CAPTURE_CRC_SYN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_CRC_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_CRC_SYN]

//>> GET_[DLP_LINK0_SYN_CAPTURE_CRC_SYN]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_SYN_CAPTURE_CRC_SYN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return i_data.extractToRight<DLP_LINK0_SYN_CAPTURE_CRC_SYN,
           DLP_LINK0_SYN_CAPTURE_CRC_SYN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_CRC_SYN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_SYN_CAPTURE_CRC_SYN]

//>> SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN0]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN0,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN0]

//>> SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN0]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN0,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN0]

//>> GET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN0]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return i_data.extractToRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN0,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN0]

//>> SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN1]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN1,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN1]

//>> SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN1]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN1,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN1]

//>> GET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN1]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return i_data.extractToRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN1,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN1]

//>> SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN2]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN2,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN2]

//>> SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN2]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN2,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN2]

//>> GET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN2]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_SYN_CAPTURE_SLECC_SYN2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return i_data.extractToRight<DLP_LINK0_SYN_CAPTURE_SLECC_SYN2,
           DLP_LINK0_SYN_CAPTURE_SLECC_SYN2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_SLECC_SYN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_SYN_CAPTURE_SLECC_SYN2]

//>> SET_[DLP_LINK0_SYN_CAPTURE_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_RESERVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_RESERVED,
           DLP_LINK0_SYN_CAPTURE_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_RESERVED]

//>> SET_[DLP_LINK0_SYN_CAPTURE_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_RESERVED,
           DLP_LINK0_SYN_CAPTURE_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_RESERVED]

//>> GET_[DLP_LINK0_SYN_CAPTURE_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_SYN_CAPTURE_RESERVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return i_data.extractToRight<DLP_LINK0_SYN_CAPTURE_RESERVED,
           DLP_LINK0_SYN_CAPTURE_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_SYN_CAPTURE_RESERVED]

//>> SET_[DLP_LINK0_SYN_CAPTURE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_VALID]

//>> SET_[DLP_LINK0_SYN_CAPTURE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.insertFromRight<DLP_LINK0_SYN_CAPTURE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_VALID]

//>> SET_[DLP_LINK0_SYN_CAPTURE_VALID]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_SYN_CAPTURE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.setBit<DLP_LINK0_SYN_CAPTURE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK0_SYN_CAPTURE_VALID]

//>> CLEAR_[DLP_LINK0_SYN_CAPTURE_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_SYN_CAPTURE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return o_data.clearBit<DLP_LINK0_SYN_CAPTURE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK0_SYN_CAPTURE_VALID]

//>> GET_[DLP_LINK0_SYN_CAPTURE_VALID]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_SYN_CAPTURE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return i_data.extractToRight<DLP_LINK0_SYN_CAPTURE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_SYN_CAPTURE_VALID]

//>> GET_[DLP_LINK0_SYN_CAPTURE_VALID]
static inline bool GET_DLP_LINK0_SYN_CAPTURE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_SYN_CAPTURE));
#endif
    return i_data.getBit<DLP_LINK0_SYN_CAPTURE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK0_SYN_CAPTURE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK0_SYN_CAPTURE_VALID]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
