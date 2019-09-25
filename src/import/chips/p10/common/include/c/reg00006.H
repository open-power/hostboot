/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00006.H $            */
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

#ifndef __C_REG00006_H_
#define __C_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CERR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CERR;
#endif
    return fapi2::getScom(i_target, CPMS_CERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CERR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return fapi2::putScom(i_target, CPMS_CERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_L3_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_L3_PFET_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_L3_PFET_SEQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_L3_PFET_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_L3_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_L3_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_L3_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_L3_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_L3_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_L3_PFET_SEQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_L3_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_L3_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CL2_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_CL2_PFET_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CL2_PFET_SEQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_CL2_PFET_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CL2_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_CL2_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_CL2_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_CL2_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_CL2_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_CL2_PFET_SEQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_CL2_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_CL2_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_MMA_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_MMA_PFET_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_MMA_PFET_SEQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_MMA_PFET_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_MMA_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_MMA_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_MMA_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_MMA_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_MMA_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_MMA_PFET_SEQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_MMA_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_MMA_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_DDS_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_DDS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_DDS_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_DDS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_DDS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_DDS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_DDS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_DDS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_DDS_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_DDS_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_DDS_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_DDS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_L3_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_L3_CLOCK_SYNC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_L3_CLOCK_SYNC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_L3_CLOCK_SYNC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_L3_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_L3_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_L3_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_L3_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_L3_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_L3_CLOCK_SYNC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_L3_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_L3_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CL2_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_CL2_CLOCK_SYNC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CL2_CLOCK_SYNC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_CL2_CLOCK_SYNC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CL2_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_CL2_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_CL2_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_CL2_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_CL2_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_CL2_CLOCK_SYNC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_CL2_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_CL2_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_DPT_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_DPT_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_DPT_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_DPT_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_DPT_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_DPT_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_DPT_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_DPT_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_DPT_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_DPT_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_DPT_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_DPT_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PROXY_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_PROXY_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PROXY_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_PROXY_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PROXY_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_PROXY_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_PROXY_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_PROXY_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_PROXY_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_PROXY_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_PROXY_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_PROXY_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_SPARE_ERR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_SPARE_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_SPARE_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_SPARE_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_SPARE_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_SPARE_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_SPARE_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_SPARE_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_SPARE_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_SPARE_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_SPARE_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_SPARE_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_SPARE_ERR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_SPARE_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_SPARE_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CERR_SPARE_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_SPARE_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_SPARE_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_FTC_DEBUG_EVENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_FTC_DEBUG_EVENT,
           CPMS_CERR_FTC_DEBUG_EVENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_FTC_DEBUG_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_FTC_DEBUG_EVENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_FTC_DEBUG_EVENT,
           CPMS_CERR_FTC_DEBUG_EVENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_FTC_DEBUG_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_FTC_DEBUG_EVENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_FTC_DEBUG_EVENT,
           CPMS_CERR_FTC_DEBUG_EVENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CERR_FTC_DEBUG_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CUCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CUCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CUCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CUCR;
#endif
    return fapi2::getScom(i_target, CPMS_CUCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CUCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return fapi2::putScom(i_target, CPMS_CUCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CUCR_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CUCR_SCOM1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CUCR_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CUCR_SCOM1;
#endif
    return fapi2::getScom(i_target, CPMS_CUCR_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CUCR_SCOM1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return fapi2::putScom(i_target, CPMS_CUCR_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CUCR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CUCR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CUCR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CUCR_SCOM2;
#endif
    return fapi2::getScom(i_target, CPMS_CUCR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CUCR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return fapi2::putScom(i_target, CPMS_CUCR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_ENABLE_CORE_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_ENABLE_CORE_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_ENABLE_CORE_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_ENABLE_CORE_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_ENABLE_CORE_SHADOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_ENABLE_CORE_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_ENABLE_CORE_SAMPLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SAMPLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_ENABLE_CORE_SAMPLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_ENABLE_CORE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_ENABLE_CORE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_ENABLE_CORE_SAMPLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_ENABLE_CORE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_PER_THREAD_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_PER_THREAD_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_PER_THREAD_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_DPT_PER_THREAD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_DPT_PER_THREAD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_DPT_PER_THREAD_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_DPT_PER_THREAD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_SPARE,
           CPMS_CUCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_SPARE,
           CPMS_CUCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_SPARE,
           CPMS_CUCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_STOP01_SAMPLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_STOP01_SAMPLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_STOP01_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_STOP01_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_STOP01_SAMPLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_STOP01_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_FTC_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_FTC_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_FTC_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_REFRESH_FTC_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_REFRESH_FTC_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_REFRESH_FTC_SHADOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_REFRESH_FTC_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_PP_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_PP_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_PP_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_REFRESH_PP_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_REFRESH_PP_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_REFRESH_PP_SHADOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_REFRESH_PP_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_DPT_SETTINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_DPT_SETTINGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_DPT_SETTINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_REFRESH_DPT_SETTINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_REFRESH_DPT_SETTINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_REFRESH_DPT_SETTINGS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_REFRESH_DPT_SETTINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_INDUCED_DROOP_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_INDUCED_DROOP_COUNT,
           CPMS_CUCR_INDUCED_DROOP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_INDUCED_DROOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_INDUCED_DROOP_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_INDUCED_DROOP_COUNT,
           CPMS_CUCR_INDUCED_DROOP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_INDUCED_DROOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_INDUCED_DROOP_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_INDUCED_DROOP_COUNT,
           CPMS_CUCR_INDUCED_DROOP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_INDUCED_DROOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PCB_SKEW_ADJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PCB_SKEW_ADJ,
           CPMS_CUCR_PCB_SKEW_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PCB_SKEW_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PCB_SKEW_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PCB_SKEW_ADJ,
           CPMS_CUCR_PCB_SKEW_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PCB_SKEW_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_PCB_SKEW_ADJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_PCB_SKEW_ADJ,
           CPMS_CUCR_PCB_SKEW_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PCB_SKEW_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FTC_SHADOW_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FTC_SHADOW_STATE,
           CPMS_CUCR_FTC_SHADOW_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FTC_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FTC_SHADOW_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FTC_SHADOW_STATE,
           CPMS_CUCR_FTC_SHADOW_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FTC_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_FTC_SHADOW_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_FTC_SHADOW_STATE,
           CPMS_CUCR_FTC_SHADOW_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FTC_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FTC_SHADOW_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FTC_SHADOW_PENDING,
           CPMS_CUCR_FTC_SHADOW_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FTC_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FTC_SHADOW_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FTC_SHADOW_PENDING,
           CPMS_CUCR_FTC_SHADOW_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FTC_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_FTC_SHADOW_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_FTC_SHADOW_PENDING,
           CPMS_CUCR_FTC_SHADOW_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FTC_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PP_SHADOW_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PP_SHADOW_STATE,
           CPMS_CUCR_PP_SHADOW_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PP_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PP_SHADOW_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PP_SHADOW_STATE,
           CPMS_CUCR_PP_SHADOW_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PP_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_PP_SHADOW_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_PP_SHADOW_STATE,
           CPMS_CUCR_PP_SHADOW_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PP_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PP_SHADOW_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PP_SHADOW_PENDING,
           CPMS_CUCR_PP_SHADOW_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PP_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PP_SHADOW_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PP_SHADOW_PENDING,
           CPMS_CUCR_PP_SHADOW_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PP_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_PP_SHADOW_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_PP_SHADOW_PENDING,
           CPMS_CUCR_PP_SHADOW_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_PP_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_UPDATE_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_UPDATE_STATE,
           CPMS_CUCR_DPT_UPDATE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_UPDATE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_UPDATE_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_UPDATE_STATE,
           CPMS_CUCR_DPT_UPDATE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_UPDATE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_DPT_UPDATE_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_DPT_UPDATE_STATE,
           CPMS_CUCR_DPT_UPDATE_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_UPDATE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_UPDATE_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_UPDATE_PENDING,
           CPMS_CUCR_DPT_UPDATE_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_UPDATE_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_UPDATE_PENDING,
           CPMS_CUCR_DPT_UPDATE_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_DPT_UPDATE_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_DPT_UPDATE_PENDING,
           CPMS_CUCR_DPT_UPDATE_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_DPT_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_REFRESH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_REFRESH_ACTIVE,
           CPMS_CUCR_CORE_REFRESH_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_REFRESH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_REFRESH_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_REFRESH_ACTIVE,
           CPMS_CUCR_CORE_REFRESH_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_REFRESH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_CORE_REFRESH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_CORE_REFRESH_ACTIVE,
           CPMS_CUCR_CORE_REFRESH_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_CORE_REFRESH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_DATA_TYPE1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_DATA_TYPE1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_DATA_TYPE1_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_DATA_TYPE1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_DATA_TYPE2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_DATA_TYPE2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_DATA_TYPE2_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_DATA_TYPE2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_DATA_TYPE3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_DATA_TYPE3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_DATA_TYPE3_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_DATA_TYPE3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FDCR_UPDATE_INPROGRESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FDCR_UPDATE_INPROGRESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_FDCR_UPDATE_INPROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_FDCR_UPDATE_INPROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_FDCR_UPDATE_INPROGRESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_FDCR_UPDATE_INPROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM1, CPMS_CUCR_SCOM2));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DPPR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DPPR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR;
#endif
    return fapi2::getScom(i_target, CPMS_DPPR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPPR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return fapi2::putScom(i_target, CPMS_DPPR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DPPR_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR_SCOM1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DPPR_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR_SCOM1;
#endif
    return fapi2::getScom(i_target, CPMS_DPPR_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPPR_SCOM1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return fapi2::putScom(i_target, CPMS_DPPR_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DPPR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DPPR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR_SCOM2;
#endif
    return fapi2::getScom(i_target, CPMS_DPPR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPPR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return fapi2::putScom(i_target, CPMS_DPPR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_RESET_ACTIVITY_PROXY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ACTIVITY_PROXY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_RESET_ACTIVITY_PROXY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_RESET_ACTIVITY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_RESET_ACTIVITY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_RESET_ACTIVITY_PROXY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_RESET_ACTIVITY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_RESET_ENERGY_PROXY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ENERGY_PROXY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_RESET_ENERGY_PROXY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_RESET_ENERGY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_RESET_ENERGY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_RESET_ENERGY_PROXY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_RESET_ENERGY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_INTERVAL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_INTERVAL_SEL,
           CPMS_DPPR_PIL_INTERVAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_INTERVAL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_INTERVAL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_INTERVAL_SEL,
           CPMS_DPPR_PIL_INTERVAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_INTERVAL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PIL_INTERVAL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PIL_INTERVAL_SEL,
           CPMS_DPPR_PIL_INTERVAL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_INTERVAL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_RATE_FLOOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_RATE_FLOOR,
           CPMS_DPPR_PIL_RATE_FLOOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_RATE_FLOOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_RATE_FLOOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_RATE_FLOOR,
           CPMS_DPPR_PIL_RATE_FLOOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_RATE_FLOOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PIL_RATE_FLOOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PIL_RATE_FLOOR,
           CPMS_DPPR_PIL_RATE_FLOOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_RATE_FLOOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_RATE_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_RATE_OFFSET,
           CPMS_DPPR_PIL_RATE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_RATE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_RATE_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_RATE_OFFSET,
           CPMS_DPPR_PIL_RATE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_RATE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PIL_RATE_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PIL_RATE_OFFSET,
           CPMS_DPPR_PIL_RATE_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_RATE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_BLOCKED_ADDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_BLOCKED_ADDER,
           CPMS_DPPR_PIL_BLOCKED_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_BLOCKED_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_BLOCKED_ADDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_BLOCKED_ADDER,
           CPMS_DPPR_PIL_BLOCKED_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_BLOCKED_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PIL_BLOCKED_ADDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PIL_BLOCKED_ADDER,
           CPMS_DPPR_PIL_BLOCKED_ADDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_BLOCKED_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_BLOCKED_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_BLOCKED_THRESH,
           CPMS_DPPR_PIL_BLOCKED_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_BLOCKED_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_BLOCKED_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_BLOCKED_THRESH,
           CPMS_DPPR_PIL_BLOCKED_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_BLOCKED_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PIL_BLOCKED_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PIL_BLOCKED_THRESH,
           CPMS_DPPR_PIL_BLOCKED_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PIL_BLOCKED_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_ENABLE,
           CPMS_DPPR_OCP_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_ENABLE,
           CPMS_DPPR_OCP_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_ENABLE,
           CPMS_DPPR_OCP_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_FTX_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_FTX_TUNE,
           CPMS_DPPR_OCP_FTX_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_FTX_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_FTX_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_FTX_TUNE,
           CPMS_DPPR_OCP_FTX_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_FTX_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_FTX_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_FTX_TUNE,
           CPMS_DPPR_OCP_FTX_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_FTX_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_ADDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_ADDER,
           CPMS_DPPR_OCP_LOCAL_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_ADDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_ADDER,
           CPMS_DPPR_OCP_LOCAL_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_LOCAL_ADDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_LOCAL_ADDER,
           CPMS_DPPR_OCP_LOCAL_ADDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_WAIT_FOR_GRANT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_WAIT_FOR_GRANT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_WAIT_FOR_GRANT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_WAIT_FOR_GRANT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_WAIT_FOR_GRANT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_WAIT_FOR_GRANT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_MSB_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_MSB_MAX,
           CPMS_DPPR_OCP_LOCAL_MSB_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_MSB_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_MSB_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_MSB_MAX,
           CPMS_DPPR_OCP_LOCAL_MSB_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_MSB_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_LOCAL_MSB_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_LOCAL_MSB_MAX,
           CPMS_DPPR_OCP_LOCAL_MSB_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_MSB_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_OVERAGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_OVERAGE,
           CPMS_DPPR_OCP_LOCAL_OVERAGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_OVERAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_OVERAGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_OVERAGE,
           CPMS_DPPR_OCP_LOCAL_OVERAGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_OVERAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_LOCAL_OVERAGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_LOCAL_OVERAGE,
           CPMS_DPPR_OCP_LOCAL_OVERAGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_OVERAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_TANK_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_TANK_VALUE,
           CPMS_DPPR_OCP_LOCAL_TANK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_TANK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_TANK_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_TANK_VALUE,
           CPMS_DPPR_OCP_LOCAL_TANK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_TANK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_LOCAL_TANK_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_LOCAL_TANK_VALUE,
           CPMS_DPPR_OCP_LOCAL_TANK_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_LOCAL_TANK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_PITCH_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_PITCH_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_PITCH_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_PITCH_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_PITCH_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_PITCH_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_PITCH_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_OVERRIDE_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_OVERRIDE_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_OVERRIDE_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_OVERRIDE_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_OVERRIDE_HISTORY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_OVERRIDE_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_FTX_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_FTX_SAT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_FTX_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PITCH_FTX_SAT_MAX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_FTX_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_FTX_SAT_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_FTX_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PITCH_FTX_SAT_MIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_ACCERR_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ACCERR_SAT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_ACCERR_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PITCH_ACCERR_SAT_MAX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_ACCERR_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ACCERR_SAT_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_ACCERR_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PITCH_ACCERR_SAT_MIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_APP_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_APP_SATURATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_APP_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.setBit<CPMS_DPPR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return o_data.clearBit<CPMS_DPPR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.extractToRight<CPMS_DPPR_PITCH_APP_SATURATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DPPR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_SCOM1, CPMS_DPPR_SCOM2));
#endif
    return i_data.getBit<CPMS_DPPR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPPR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_MMA_PFETCNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMA_PFETCNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_MMA_PFETCNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMA_PFETCNTL;
#endif
    return fapi2::getScom(i_target, CPMS_MMA_PFETCNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_MMA_PFETCNTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_MMA_PFETCNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_MMA_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMA_PFETCNTL_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_MMA_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMA_PFETCNTL_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_MMA_PFETCNTL_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_MMA_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_MMA_PFETCNTL_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_MMA_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMA_PFETCNTL_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_MMA_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_MMA_PFETCNTL_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_MMA_PFETCNTL_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_MMA_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_MMA_PFETCNTL_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PG_STATE,
           CPMS_MMA_PFETCNTL_VDD_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PG_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PG_STATE,
           CPMS_MMA_PFETCNTL_VDD_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETCNTL_VDD_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETCNTL_VDD_PG_STATE,
           CPMS_MMA_PFETCNTL_VDD_PG_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PG_SEL,
           CPMS_MMA_PFETCNTL_VDD_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_VDD_PG_SEL,
           CPMS_MMA_PFETCNTL_VDD_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETCNTL_VDD_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETCNTL_VDD_PG_SEL,
           CPMS_MMA_PFETCNTL_VDD_PG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3;
#endif
    return fapi2::getScom(i_target, EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return fapi2::putScom(i_target, EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_V0_HMER_RW_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_V0_HMER_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_V0_HMER_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_V0_HMER_RW_WAND;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_V0_HMER_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_V0_HMER_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_V0_HMER_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_V0_HMER_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_V0_HMER_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_V0_HMER_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_V0_HMER_WO_OR;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_V0_HMER_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_V0_HMER_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_V0_HMER_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_MALFUNCTION_ALERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_QME_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TFAC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_PROC_RCVY_AGAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_SCOM_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_TRIG_FIR_HMI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_SPARE_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_V0_HMER_SPARE_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_SPARE_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_V0_HMER_SPARE_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_V0_HMER_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_SPARE_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_V0_HMER_RW_WAND, EC_PC_COMMON_SPR_V0_HMER_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS,
           EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_V0_HMER_V0_HMER_XSCOM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_RW;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_WO_AND;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_WO_OR;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_IF_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_STF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_VS_STF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SD_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SD_L2_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_TLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_MU_TLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_MU_SLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_CXT_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_MU_CXT_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_VS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_LS_SETDELETE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_LS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_SCOM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_SCOM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_FIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_FIRMASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_FIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_FIRMASK_RW;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_FIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_FIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_FIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_FIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_FIRMASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_FIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_FIRMASK_WO_AND;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_FIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_FIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_FIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_FIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_FIRMASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_FIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_FIRMASK_WO_OR;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_FIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_FIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_FIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_ERR_INJ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_ERR_INJ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_ERR_INJ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_ERR_INJ;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_ERR_INJ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_ERR_INJ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_ERR_INJ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK,
           EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK,
           EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK,
           EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.setBit<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.clearBit<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.getBit<EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL,
           EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL,
           EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL,
           EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK,
           EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return o_data.insertFromRight<EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK,
           EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_ERR_INJ));
#endif
    return i_data.extractToRight<EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK,
           EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS;
#endif
    return fapi2::getScom(i_target, EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return fapi2::putScom(i_target, EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_4_A,
           EC_PC_TRACE1_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_4_A,
           EC_PC_TRACE1_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR0_CONFIG_4_A,
           EC_PC_TRACE1_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_4_B,
           EC_PC_TRACE1_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_4_B,
           EC_PC_TRACE1_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR0_CONFIG_4_B,
           EC_PC_TRACE1_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR0_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR0_CONFIG;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR0_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR0_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE,
           EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE,
           EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE,
           EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_BANK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_BANK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL,
           EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL,
           EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL,
           EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_MASK_REG_RW, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_MASK_REG_RW, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_MASK_REG_RW, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_MASK_REG_RW, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK,
           L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_MASK_REG_RW, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK,
           L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_MASK_REG_RW, L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND,
                           L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK,
           L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_2_A,
           L2TRA_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_2_A,
           L2TRA_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_2_A,
           L2TRA_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_2_B,
           L2TRA_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_2_B,
           L2TRA_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_2_B,
           L2TRA_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_MODE_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_MODE_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_MODE_REG2;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_MODE_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_MODE_REG2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_MODE_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_MODE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV,
           NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WRITE_PROTECT_RINGS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_PROTECT_RINGS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WRITE_PROTECT_RINGS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_PROTECT_RINGS_REG;
#endif
    return fapi2::getScom(i_target, WRITE_PROTECT_RINGS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WRITE_PROTECT_RINGS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_RINGS_REG));
#endif
    return fapi2::putScom(i_target, WRITE_PROTECT_RINGS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_RINGS_REG));
#endif
    return o_data.insertFromRight<WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS,
           WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_RINGS_REG));
#endif
    return o_data.insertFromRight<WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS,
           WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_RINGS_REG));
#endif
    return i_data.extractToRight<WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS,
           WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
