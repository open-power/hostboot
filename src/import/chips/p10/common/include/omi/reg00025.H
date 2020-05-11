/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00025.H $          */
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

#ifndef __OMI_REG00025_H_
#define __OMI_REG00025_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[TRAINING_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRAINING_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRAINING_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRAINING_STATUS]

//>> GET_[TRAINING_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRAINING_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRAINING_STATUS;
#endif
    return fapi2::getScom(i_target, TRAINING_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRAINING_STATUS]

//>> PUT_[TRAINING_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRAINING_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return fapi2::putScom(i_target, TRAINING_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRAINING_STATUS]


//>> SET_[TRAINING_STATUS_RX_PATTERN_A]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_PATTERN_A,
           TRAINING_STATUS_RX_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TRAINING_STATUS_RX_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_PATTERN_A]

//>> SET_[TRAINING_STATUS_RX_PATTERN_A]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_PATTERN_A,
           TRAINING_STATUS_RX_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TRAINING_STATUS_RX_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_PATTERN_A]

//>> GET_[TRAINING_STATUS_RX_PATTERN_A]
static inline fapi2::buffer<uint64_t>& GET_TRAINING_STATUS_RX_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return i_data.extractToRight<TRAINING_STATUS_RX_PATTERN_A,
           TRAINING_STATUS_RX_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TRAINING_STATUS_RX_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRAINING_STATUS_RX_PATTERN_A]

//>> SET_[TRAINING_STATUS_RX_PATTERN_B]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_PATTERN_B,
           TRAINING_STATUS_RX_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TRAINING_STATUS_RX_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_PATTERN_B]

//>> SET_[TRAINING_STATUS_RX_PATTERN_B]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_PATTERN_B,
           TRAINING_STATUS_RX_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TRAINING_STATUS_RX_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_PATTERN_B]

//>> GET_[TRAINING_STATUS_RX_PATTERN_B]
static inline fapi2::buffer<uint64_t>& GET_TRAINING_STATUS_RX_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return i_data.extractToRight<TRAINING_STATUS_RX_PATTERN_B,
           TRAINING_STATUS_RX_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TRAINING_STATUS_RX_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRAINING_STATUS_RX_PATTERN_B]

//>> SET_[TRAINING_STATUS_SYNC_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_SYNC_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_SYNC_PATTERN,
           TRAINING_STATUS_SYNC_PATTERN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TRAINING_STATUS_SYNC_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_SYNC_PATTERN]

//>> SET_[TRAINING_STATUS_SYNC_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_SYNC_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_SYNC_PATTERN,
           TRAINING_STATUS_SYNC_PATTERN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TRAINING_STATUS_SYNC_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_SYNC_PATTERN]

//>> GET_[TRAINING_STATUS_SYNC_PATTERN]
static inline fapi2::buffer<uint64_t>& GET_TRAINING_STATUS_SYNC_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return i_data.extractToRight<TRAINING_STATUS_SYNC_PATTERN,
           TRAINING_STATUS_SYNC_PATTERN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TRAINING_STATUS_SYNC_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRAINING_STATUS_SYNC_PATTERN]

//>> SET_[TRAINING_STATUS_PHY_INIT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_PHY_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_PHY_INIT_DONE,
           TRAINING_STATUS_PHY_INIT_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TRAINING_STATUS_PHY_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_PHY_INIT_DONE]

//>> SET_[TRAINING_STATUS_PHY_INIT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_PHY_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_PHY_INIT_DONE,
           TRAINING_STATUS_PHY_INIT_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TRAINING_STATUS_PHY_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_PHY_INIT_DONE]

//>> GET_[TRAINING_STATUS_PHY_INIT_DONE]
static inline fapi2::buffer<uint64_t>& GET_TRAINING_STATUS_PHY_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return i_data.extractToRight<TRAINING_STATUS_PHY_INIT_DONE,
           TRAINING_STATUS_PHY_INIT_DONE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TRAINING_STATUS_PHY_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRAINING_STATUS_PHY_INIT_DONE]

//>> SET_[TRAINING_STATUS_BLOCK_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_BLOCK_LOCKED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_BLOCK_LOCKED,
           TRAINING_STATUS_BLOCK_LOCKED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TRAINING_STATUS_BLOCK_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_BLOCK_LOCKED]

//>> SET_[TRAINING_STATUS_BLOCK_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_BLOCK_LOCKED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_BLOCK_LOCKED,
           TRAINING_STATUS_BLOCK_LOCKED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TRAINING_STATUS_BLOCK_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_BLOCK_LOCKED]

//>> GET_[TRAINING_STATUS_BLOCK_LOCKED]
static inline fapi2::buffer<uint64_t>& GET_TRAINING_STATUS_BLOCK_LOCKED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return i_data.extractToRight<TRAINING_STATUS_BLOCK_LOCKED,
           TRAINING_STATUS_BLOCK_LOCKED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TRAINING_STATUS_BLOCK_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRAINING_STATUS_BLOCK_LOCKED]

//>> SET_[TRAINING_STATUS_RX_TS1]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_TS1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_TS1,
           TRAINING_STATUS_RX_TS1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TRAINING_STATUS_RX_TS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_TS1]

//>> SET_[TRAINING_STATUS_RX_TS1]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_TS1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_TS1,
           TRAINING_STATUS_RX_TS1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TRAINING_STATUS_RX_TS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_TS1]

//>> GET_[TRAINING_STATUS_RX_TS1]
static inline fapi2::buffer<uint64_t>& GET_TRAINING_STATUS_RX_TS1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return i_data.extractToRight<TRAINING_STATUS_RX_TS1,
           TRAINING_STATUS_RX_TS1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TRAINING_STATUS_RX_TS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRAINING_STATUS_RX_TS1]

//>> SET_[TRAINING_STATUS_RX_TS2]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_TS2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_TS2,
           TRAINING_STATUS_RX_TS2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TRAINING_STATUS_RX_TS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_TS2]

//>> SET_[TRAINING_STATUS_RX_TS2]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_TS2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_TS2,
           TRAINING_STATUS_RX_TS2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TRAINING_STATUS_RX_TS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_TS2]

//>> GET_[TRAINING_STATUS_RX_TS2]
static inline fapi2::buffer<uint64_t>& GET_TRAINING_STATUS_RX_TS2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return i_data.extractToRight<TRAINING_STATUS_RX_TS2,
           TRAINING_STATUS_RX_TS2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TRAINING_STATUS_RX_TS2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRAINING_STATUS_RX_TS2]

//>> SET_[TRAINING_STATUS_RX_TS3]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_TS3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_TS3,
           TRAINING_STATUS_RX_TS3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TRAINING_STATUS_RX_TS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_TS3]

//>> SET_[TRAINING_STATUS_RX_TS3]
static inline fapi2::buffer<uint64_t>& SET_TRAINING_STATUS_RX_TS3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return o_data.insertFromRight<TRAINING_STATUS_RX_TS3,
           TRAINING_STATUS_RX_TS3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TRAINING_STATUS_RX_TS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRAINING_STATUS_RX_TS3]

//>> GET_[TRAINING_STATUS_RX_TS3]
static inline fapi2::buffer<uint64_t>& GET_TRAINING_STATUS_RX_TS3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRAINING_STATUS));
#endif
    return i_data.extractToRight<TRAINING_STATUS_RX_TS3,
           TRAINING_STATUS_RX_TS3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TRAINING_STATUS_RX_TS3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRAINING_STATUS_RX_TS3]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
