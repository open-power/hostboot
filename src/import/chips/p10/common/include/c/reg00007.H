/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00007.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __C_REG00007_H_
#define __C_REG00007_H_

namespace scomt
{
namespace c
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CERRMSK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CERRMSK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CERRMSK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CERRMSK;
#endif
    return fapi2::getScom(i_target, CPMS_CERRMSK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CERRMSK(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return fapi2::putScom(i_target, CPMS_CERRMSK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PFET_SEQ_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_PFET_SEQ_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_PFET_SEQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_PFET_SEQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_PFET_SEQ_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERRMSK_PFET_SEQ_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_PFET_SEQ_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_PFET_SEQ_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_DDS_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DDS_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_DDS_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_DDS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_DDS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_DDS_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERRMSK_DDS_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_DDS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DDS_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_CLK_SYNC_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_CLK_SYNC_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_CLK_SYNC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_CLK_SYNC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_CLK_SYNC_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERRMSK_CLK_SYNC_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_CLK_SYNC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_CLK_SYNC_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_DPT_ACCESS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DPT_ACCESS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_DPT_ACCESS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_DPT_ACCESS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_DPT_ACCESS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_DPT_ACCESS_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERRMSK_DPT_ACCESS_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_DPT_ACCESS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_DPT_ACCESS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.setBit<CPMS_CERRMSK_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.clearBit<CPMS_CERRMSK_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERRMSK_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.getBit<CPMS_CERRMSK_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_FTC_EVENT_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_FTC_EVENT_MASK,
           CPMS_CERRMSK_FTC_EVENT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_FTC_EVENT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERRMSK_FTC_EVENT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return o_data.insertFromRight<CPMS_CERRMSK_FTC_EVENT_MASK,
           CPMS_CERRMSK_FTC_EVENT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_FTC_EVENT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERRMSK_FTC_EVENT_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERRMSK));
#endif
    return i_data.extractToRight<CPMS_CERRMSK_FTC_EVENT_MASK,
           CPMS_CERRMSK_FTC_EVENT_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERRMSK_FTC_EVENT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG0;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG0));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_HOLD_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_HOLD_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_HOLD_OUT;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_HOLD_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_HOLD_OUT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_HOLD_OUT));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_HOLD_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_RAM_MODEREG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RAM_MODEREG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_RAM_MODEREG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RAM_MODEREG;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_RAM_MODEREG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_RAM_MODEREG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_RAM_MODEREG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return o_data.setBit<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return o_data.clearBit<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_MODEREG));
#endif
    return i_data.getBit<EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SCR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SCR2(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR2;
#endif
    return fapi2::getScom(i_target, EC_PC_SCR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SCR2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SCR2));
#endif
    return fapi2::putScom(i_target, EC_PC_SCR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_RAS_MODEREG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_RAS_MODEREG;
#endif
    return fapi2::getScom(i_target, EC_PC_THRCTL_TCTLCOM_RAS_MODEREG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_THRCTL_TCTLCOM_RAS_MODEREG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_RAS_MODEREG));
#endif
    return fapi2::putScom(i_target, EC_PC_THRCTL_TCTLCOM_RAS_MODEREG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR0_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR0_CONFIG_0;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR0_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG_0));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR0_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG_0));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA,
           L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA,
           L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA,
           L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS,
           L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS,
           L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS,
           L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_4;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_4));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_4_A,
           L2TRA_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_4_A,
           L2TRA_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_4_A,
           L2TRA_TR1_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_4_B,
           L2TRA_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_4_B,
           L2TRA_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_4_B,
           L2TRA_TR1_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_PRD_PURGE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PRD_PURGE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_PRD_PURGE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PRD_PURGE_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_PRD_PURGE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_PRD_PURGE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_PRD_PURGE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PRD_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31,
           L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_STATUS_REG;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_STATUS_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PSCRS3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PSCRS3(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS3;
#endif
    return fapi2::getScom(i_target, QME_PSCRS3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PSCRS3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return fapi2::putScom(i_target, QME_PSCRS3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DPDES_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_DPDES_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_SD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_SD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_SD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_ESL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_ESL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_ESL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_EC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_EC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_PSLL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_PSLL,
           QME_PSCRS3_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_PSLL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_PSLL,
           QME_PSCRS3_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_PSLL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_PSLL,
           QME_PSCRS3_PSLL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_UV_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_UV_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_HYP_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EXT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_EXT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DEC_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_DEC_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HMI_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.setBit<QME_PSCRS3_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.clearBit<QME_PSCRS3_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_HMI_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_PSCRS3_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.getBit<QME_PSCRS3_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_,
           QME_PSCRS3__LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_,
           QME_PSCRS3__LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_,
           QME_PSCRS3__LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_MTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_MTL,
           QME_PSCRS3_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_MTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_MTL,
           QME_PSCRS3_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_MTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_MTL,
           QME_PSCRS3_MTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_RL,
           QME_PSCRS3_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_RL,
           QME_PSCRS3_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_RL,
           QME_PSCRS3_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_PLS,
           QME_PSCRS3_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS3_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return o_data.insertFromRight<QME_PSCRS3_PLS,
           QME_PSCRS3_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS3_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS3));
#endif
    return i_data.extractToRight<QME_PSCRS3_PLS,
           QME_PSCRS3_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_PSCRS3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR;
#endif
    return fapi2::getScom(i_target, QME_SCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return fapi2::putScom(i_target, QME_SCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCSR_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR_SCOM1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCSR_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR_SCOM1;
#endif
    return fapi2::getScom(i_target, QME_SCSR_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCSR_SCOM1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return fapi2::putScom(i_target, QME_SCSR_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCSR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCSR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCSR_SCOM2;
#endif
    return fapi2::getScom(i_target, QME_SCSR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCSR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return fapi2::putScom(i_target, QME_SCSR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_BLOCK_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_ASSERT_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_ASSERT_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_ASSERT_PM_BLOCK_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_ASSERT_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_ASSERT_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_EXIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_ASSERT_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_ASSERT_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_ASSERT_PM_EXIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_ASSERT_PM_EXIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_ASSERT_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_ENTRY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_PM_ENTRY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_ASSERT_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_ASSERT_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_ASSERT_PM_ENTRY_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_ASSERT_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_ASSERT_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_SPARE_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_SPARE_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PC_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PC_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PC_SPARE_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PC_SPARE_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PC_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_HBUS_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_HBUS_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_HBUS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_HBUS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_HBUS_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_HBUS_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_HBUS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_L2_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_L2_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_L2_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_L2_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_L2_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_L2_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_L2_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_L2_PURGE_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_L2_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_L2_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_L2RCMD_INTF_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2RCMD_INTF_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_L2RCMD_INTF_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_L2RCMD_INTF_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_L2RCMD_INTF_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_L2RCMD_INTF_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_L2RCMD_INTF_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_L2RCMD_INTF_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2RCMD_INTF_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_TLBIE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_TLBIE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_TLBIE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_NCU_TLBIE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_NCU_TLBIE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_NCU_TLBIE_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_NCU_TLBIE_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_NCU_TLBIE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_TLBIE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_NCU_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_NCU_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_NCU_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_NCU_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_NCU_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_NCU_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_NCU_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_NCU_PURGE_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_NCU_PURGE_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_NCU_PURGE_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CHTM_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CHTM_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_CHTM_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_CHTM_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_CHTM_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_CHTM_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_CHTM_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PB_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PB_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PB_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PB_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PB_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PB_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PB_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_CORE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_CORE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_CORE_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_CORE_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_CORE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_SPARE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_SPARE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_SPARE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_SPARE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_SPARE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SRESET_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SRESET_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SRESET_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_SRESET_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_SRESET_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_SRESET_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_SRESET_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_SRESET_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SRESET_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_ASSERT_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_ASSERT_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ASSERT_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_SPARE_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_SPARE_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_SPARE_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_SPARE18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPARE18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_SPARE18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPARE18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_SPARE18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_SPARE18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_SPARE18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_IGNORE_PMCR_RECENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_IGNORE_PMCR_RECENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_IGNORE_PMCR_RECENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_IGNORE_PMCR_RECENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_IGNORE_PMCR_RECENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_IGNORE_PMCR_RECENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_IGNORE_PMCR_RECENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_IGNORE_PMCR_RECENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_IGNORE_PMCR_RECENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_AUTO_PMSR_SHIFT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_AUTO_PMSR_SHIFT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_AUTO_PMSR_SHIFT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_AUTO_PMSR_SHIFT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_AUTO_PMSR_SHIFT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_AUTO_PMSR_SHIFT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_AUTO_PMSR_SHIFT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_AUTO_PMSR_SHIFT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_REFRESH_PMSR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REFRESH_PMSR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_REFRESH_PMSR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_REFRESH_PMSR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_REFRESH_PMSR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_REFRESH_PMSR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_REFRESH_PMSR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_REFRESH_PMSR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_REFRESH_PMSR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_OUTPUTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_BLOCK_INTR_INPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_INPUTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_BLOCK_INTR_INPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_BLOCK_INTR_INPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_BLOCK_INTR_INPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_BLOCK_INTR_INPUTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_BLOCK_INTR_INPUTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_BLOCK_INTR_INPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_BLOCK_INTR_INPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ENABLE_PECE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ENABLE_PECE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_ENABLE_PECE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_ENABLE_PECE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_ENABLE_PECE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_ENABLE_PECE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_ENABLE_PECE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_ENABLE_PECE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_ENABLE_PECE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CTFS_WKUP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CTFS_WKUP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CTFS_WKUP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_CTFS_WKUP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_CTFS_WKUP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_CTFS_WKUP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_CTFS_WKUP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_CTFS_WKUP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CTFS_WKUP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_BLOCK_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PM_BLOCK_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_EXIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PM_EXIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_ENTRY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_ENTRY_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_ENTRY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PM_ENTRY_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PM_ENTRY_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PM_ENTRY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_ENTRY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_SPARE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_SPARE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PC_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PC_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PC_SPARE_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PC_SPARE_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PC_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_HBUS_INACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_INACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_HBUS_INACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_HBUS_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_HBUS_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_HBUS_INACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_HBUS_INACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_HBUS_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_HBUS_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_L2_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_L2_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_L2_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_L2_PURGE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_L2_PURGE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_L2_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_L2_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_NCU_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_NCU_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_NCU_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_NCU_PURGE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_NCU_PURGE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_NCU_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_NCU_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CHTM_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CHTM_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_CHTM_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_CHTM_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_CHTM_PURGE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_CHTM_PURGE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_CHTM_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CHTM_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PB_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PB_PURGE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PB_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PB_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PB_PURGE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PB_PURGE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PB_PURGE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PB_PURGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_CORE_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_CORE_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_CORE_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_CORE_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_CORE_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_CORE_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_CORE_QUIESCED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_STOP_SHIFT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_STOP_SHIFT_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_STOP_SHIFT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_STOP_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_STOP_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_STOP_SHIFT_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_STOP_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_STOP_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_STOP_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_SPARE_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_SPARE_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_SPARE_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_SPARE_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_SPARE_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PSSCR_POWEROFF_ALLOWED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PSSCR_POWEROFF_ALLOWED,
           QME_SCSR_PSSCR_POWEROFF_ALLOWED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PSSCR_POWEROFF_ALLOWED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PSSCR_POWEROFF_ALLOWED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PSSCR_POWEROFF_ALLOWED,
           QME_SCSR_PSSCR_POWEROFF_ALLOWED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PSSCR_POWEROFF_ALLOWED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PSSCR_POWEROFF_ALLOWED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PSSCR_POWEROFF_ALLOWED,
           QME_SCSR_PSSCR_POWEROFF_ALLOWED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PSSCR_POWEROFF_ALLOWED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_THREAD_INSTR_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_THREAD_INSTR_RUNNING,
           QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_THREAD_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_THREAD_INSTR_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_THREAD_INSTR_RUNNING,
           QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_THREAD_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_THREAD_INSTR_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PC_THREAD_INSTR_RUNNING,
           QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_THREAD_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PMSR_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PMSR_SHIFT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PMSR_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PMSR_SHIFT_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PMSR_SHIFT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PMSR_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PMSR_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PMSR_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PMSR_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PMSR_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PMSR_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PMSR_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PMSR_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PMSR_SHIFT_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PMSR_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PMSR_SHIFT_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PMSR_SHIFT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PMSR_SHIFT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_OTHER_DPDES_INTR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_OTHER_DPDES_INTR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_OTHER_DPDES_INTR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_OTHER_DPDES_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_OTHER_DPDES_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_OTHER_DPDES_INTR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_OTHER_DPDES_INTR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_OTHER_DPDES_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_OTHER_DPDES_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_UNMASKED_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_UNMASKED_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PC_UNMASKED_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PC_UNMASKED_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PC_UNMASKED_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PC_UNMASKED_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PC_UNMASKED_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_STATE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_STATE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.setBit<QME_SCSR_PM_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.clearBit<QME_SCSR_PM_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PM_STATE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SCSR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.getBit<QME_SCSR_PM_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_STATE,
           QME_SCSR_PM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SCSR_PM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_SCSR_PM_STATE,
           QME_SCSR_PM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SCSR_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCSR, QME_SCSR_SCOM1, QME_SCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_SCSR_PM_STATE,
           QME_SCSR_PM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SCSR_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_TFCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_TFCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR;
#endif
    return fapi2::getScom(i_target, QME_TFCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_TFCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return fapi2::putScom(i_target, QME_TFCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_TFCSR_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR_SCOM1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_TFCSR_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR_SCOM1;
#endif
    return fapi2::getScom(i_target, QME_TFCSR_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_TFCSR_SCOM1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return fapi2::putScom(i_target, QME_TFCSR_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_TFCSR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_TFCSR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TFCSR_SCOM2;
#endif
    return fapi2::getScom(i_target, QME_TFCSR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_TFCSR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return fapi2::putScom(i_target, QME_TFCSR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.setBit<QME_TFCSR_XFER_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.clearBit<QME_TFCSR_XFER_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_XFER_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_TFCSR_XFER_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.getBit<QME_TFCSR_XFER_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_TFAC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_TFAC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_TFAC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.setBit<QME_TFCSR_TFAC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.clearBit<QME_TFCSR_TFAC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_TFAC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_TFCSR_TFAC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.getBit<QME_TFCSR_TFAC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_TFAC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_CORE_NUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_CORE_NUM,
           QME_TFCSR_CORE_NUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_CORE_NUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_CORE_NUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_CORE_NUM,
           QME_TFCSR_CORE_NUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_CORE_NUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_CORE_NUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_CORE_NUM,
           QME_TFCSR_CORE_NUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_CORE_NUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_RECEIVE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_RECEIVE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_RECEIVE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.setBit<QME_TFCSR_XFER_RECEIVE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.clearBit<QME_TFCSR_XFER_RECEIVE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_XFER_RECEIVE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_TFCSR_XFER_RECEIVE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.getBit<QME_TFCSR_XFER_RECEIVE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_RECEIVE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_SENT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_SENT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_XFER_SENT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.setBit<QME_TFCSR_XFER_SENT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.clearBit<QME_TFCSR_XFER_SENT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_XFER_SENT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_TFCSR_XFER_SENT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.getBit<QME_TFCSR_XFER_SENT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_XFER_SENT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_INCOMING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_INCOMING_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_INCOMING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.setBit<QME_TFCSR_INCOMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.clearBit<QME_TFCSR_INCOMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_INCOMING_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_TFCSR_INCOMING_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.getBit<QME_TFCSR_INCOMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_INCOMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_RUNTIME_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_RUNTIME_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_RUNTIME_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.setBit<QME_TFCSR_RUNTIME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.clearBit<QME_TFCSR_RUNTIME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_RUNTIME_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_TFCSR_RUNTIME_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.getBit<QME_TFCSR_RUNTIME_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_RUNTIME_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_STATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_STATE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_STATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.setBit<QME_TFCSR_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.clearBit<QME_TFCSR_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_STATE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_TFCSR_STATE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.getBit<QME_TFCSR_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_STATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_HDEC_MSB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_HDEC_MSB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_HDEC_MSB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.setBit<QME_TFCSR_HDEC_MSB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.clearBit<QME_TFCSR_HDEC_MSB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_HDEC_MSB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_TFCSR_HDEC_MSB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.getBit<QME_TFCSR_HDEC_MSB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_HDEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_DEC_MSB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_DEC_MSB,
           QME_TFCSR_DEC_MSB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_DEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_TFCSR_DEC_MSB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return o_data.insertFromRight<QME_TFCSR_DEC_MSB,
           QME_TFCSR_DEC_MSB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_DEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_TFCSR_DEC_MSB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TFCSR, QME_TFCSR_SCOM1, QME_TFCSR_SCOM2));
#endif
    return i_data.extractToRight<QME_TFCSR_DEC_MSB,
           QME_TFCSR_DEC_MSB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_TFCSR_DEC_MSB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
