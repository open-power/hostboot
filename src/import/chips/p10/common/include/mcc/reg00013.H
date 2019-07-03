/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00013.H $          */
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

#ifndef __MCC_REG00013_H_
#define __MCC_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCPERF0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCPERF0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCPERF0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCPERF0;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCPERF0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCPERF0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCPERF0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF0_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF0_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF0_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE,
           ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE,
           ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE,
           ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT,
           ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50,
           ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50,
           ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50,
           ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_RESERVED47_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE,
           ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE,
           ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE,
           ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD,
           ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTOKEY1B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTOKEY1B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTOKEY1B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTOKEY1B;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTOKEY1B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTOKEY1B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY1B));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTOKEY1B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY1B));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B,
           CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY1B));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B,
           CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY1B));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B,
           CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1B_KEY1B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLCFG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLCFG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLCFG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLCFG2;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLCFG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLCFG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLCFG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE0_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE1_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE4_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING,
           DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_TEMPLATE7_RATE_PACING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_USTL_SOURCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_RESERVED_32_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_RESERVED_32_35,
           DSTL_DSTLCFG2_RESERVED_32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_RESERVED_32_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_RESERVED_32_35,
           DSTL_DSTLCFG2_RESERVED_32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_RESERVED_32_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_RESERVED_32_35,
           DSTL_DSTLCFG2_RESERVED_32_35_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_SEL_USTL_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_MAX_CREDIT_CHECK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE,
           DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE,
           DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE,
           DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CMD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_ARM_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_INJ_ADDR_ERR_CONT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_POPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_BOGUS_STALL_MODE_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANA_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CHANB_SEL_PSAVE_PMU_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.setBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.clearBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.getBit<DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_RESERVED_51_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_RESERVED_51_62,
           DSTL_DSTLCFG2_RESERVED_51_62_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_RESERVED_51_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG2_RESERVED_51_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG2_RESERVED_51_62,
           DSTL_DSTLCFG2_RESERVED_51_62_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_RESERVED_51_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG2_RESERVED_51_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG2));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG2_RESERVED_51_62,
           DSTL_DSTLCFG2_RESERVED_51_62_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLCFG2_RESERVED_51_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLCFG;
#endif
    return fapi2::getScom(i_target, USTL_USTLCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLCFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return fapi2::putScom(i_target, USTL_USTLCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_FAIL_CAPTURE_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_FAIL_CAPTURE_CONFIG,
           USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_FAIL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_FAIL_CAPTURE_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_FAIL_CAPTURE_CONFIG,
           USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_FAIL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_FAIL_CAPTURE_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_FAIL_CAPTURE_CONFIG,
           USTL_USTLCFG_FAIL_CAPTURE_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_FAIL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DEFAULT_META_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DEFAULT_META_DATA,
           USTL_USTLCFG_DEFAULT_META_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DEFAULT_META_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DEFAULT_META_DATA,
           USTL_USTLCFG_DEFAULT_META_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_DEFAULT_META_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_DEFAULT_META_DATA,
           USTL_USTLCFG_DEFAULT_META_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOWLAT_MISS_015_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOWLAT_MISS_015_DELAY,
           USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOWLAT_MISS_015_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOWLAT_MISS_015_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOWLAT_MISS_015_DELAY,
           USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOWLAT_MISS_015_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_LOWLAT_MISS_015_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_LOWLAT_MISS_015_DELAY,
           USTL_USTLCFG_LOWLAT_MISS_015_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOWLAT_MISS_015_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_12_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_12_16,
           USTL_USTLCFG_RESERVED_12_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_12_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_12_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_12_16,
           USTL_USTLCFG_RESERVED_12_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_12_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_RESERVED_12_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_RESERVED_12_16,
           USTL_USTLCFG_RESERVED_12_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_12_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TEMPLATE1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_TEMPLATE1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TEMPLATE1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TEMPLATE1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_TEMPLATE1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TEMPLATE1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TEMPLATE1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_TEMPLATE1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TEMPLATE1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_TEMPLATE1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_TEMPLATE1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TEMPLATE1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_TEMPLATE1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_TEMPLATE1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TEMPLATE1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_TEMPLATE1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_TEMPLATE1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TEMPLATE1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE,
           USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE,
           USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE,
           USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE,
           USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE,
           USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE,
           USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT,
           USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT,
           USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT,
           USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD,
           USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD,
           USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD,
           USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RESERVED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RESERVED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RESERVED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_RESERVED_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_RESERVED_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_RESERVED_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RESERVED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RESERVED_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RESERVED_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RESERVED_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_RESERVED_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_RESERVED_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_RESERVED_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RESERVED_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CFG_WRAP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CFG_WRAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CFG_WRAP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CFG_WRAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CFG_WRAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_CFG_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_CFG_WRAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_CFG_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_CFG_WRAP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_CFG_WRAP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_CFG_WRAP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_CFG_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RESERVED_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RESERVED_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RESERVED_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_RESERVED_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_RESERVED_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_RESERVED_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RESERVED_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_LFSR_RATE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_LFSR_RATE_SEL,
           USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_LFSR_RATE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_LFSR_RATE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_LFSR_RATE_SEL,
           USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_LFSR_RATE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_LOL_LFSR_RATE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_LOL_LFSR_RATE_SEL,
           USTL_USTLCFG_LOL_LFSR_RATE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_LFSR_RATE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW485610_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CS_HW485610_DISABLE,
           USTL_USTLCFG_CS_HW485610_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW485610_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW485610_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CS_HW485610_DISABLE,
           USTL_USTLCFG_CS_HW485610_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW485610_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_CS_HW485610_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_CS_HW485610_DISABLE,
           USTL_USTLCFG_CS_HW485610_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW485610_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_CAPTURE_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_CAPTURE_CONFIG,
           USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_CAPTURE_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_CAPTURE_CONFIG,
           USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_LOL_CAPTURE_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_LOL_CAPTURE_CONFIG,
           USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LOL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LAST_OPENCAPI_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LAST_OPENCAPI_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_LAST_OPENCAPI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_LAST_OPENCAPI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_LAST_OPENCAPI_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_LAST_OPENCAPI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_PMU_SELECT_FAIL_RSP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_PMU_SELECT_FAIL_RSP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_PMU_SELECT_FAIL_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_PMU_SELECT_FAIL_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_PMU_SELECT_FAIL_RSP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_PMU_SELECT_FAIL_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_PMU_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_PMU_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_PMU_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_PMU_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_PMU_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_PMU_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_SELECT_ALT_PERF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_PMU_SELECT_ALT_PERF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_SELECT_ALT_PERF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_PMU_SELECT_ALT_PERF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_SELECT_ALT_PERF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_PMU_SELECT_ALT_PERF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_PMU_SELECT_ALT_PERF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_PMU_SELECT_ALT_PERF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_PMU_SELECT_ALT_PERF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_PMU_SELECT_ALT_PERF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_PMU_SELECT_ALT_PERF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_PMU_SELECT_ALT_PERF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW477424_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CS_HW477424_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW477424_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CS_HW477424_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW477424_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_CS_HW477424_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_CS_HW477424_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_CS_HW477424_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_CS_HW477424_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_CS_HW477424_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_CS_HW477424_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_CS_HW477424_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW475333_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CS_HW475333_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW475333_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_CS_HW475333_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW475333_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_CS_HW475333_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_CS_HW475333_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_CS_HW475333_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_CS_HW475333_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_CS_HW475333_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_USTL_USTLCFG_CS_HW475333_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_CS_HW475333_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLCFWOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLCFWOF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLCFWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLCFWOF;
#endif
    return fapi2::getScom(i_target, USTL_USTLCFWOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLCFWOF(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLCFWOF));
#endif
    return fapi2::putScom(i_target, USTL_USTLCFWOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFWOF_A_CHANFAIL_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFWOF));
#endif
    return o_data.insertFromRight<USTL_USTLCFWOF_A_CHANFAIL_WOF,
           USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFWOF_A_CHANFAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFWOF_A_CHANFAIL_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFWOF));
#endif
    return o_data.insertFromRight<USTL_USTLCFWOF_A_CHANFAIL_WOF,
           USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFWOF_A_CHANFAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFWOF_A_CHANFAIL_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFWOF));
#endif
    return i_data.extractToRight<USTL_USTLCFWOF_A_CHANFAIL_WOF,
           USTL_USTLCFWOF_A_CHANFAIL_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFWOF_A_CHANFAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFWOF_B_CHANFAIL_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFWOF));
#endif
    return o_data.insertFromRight<USTL_USTLCFWOF_B_CHANFAIL_WOF,
           USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFWOF_B_CHANFAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFWOF_B_CHANFAIL_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFWOF));
#endif
    return o_data.insertFromRight<USTL_USTLCFWOF_B_CHANFAIL_WOF,
           USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFWOF_B_CHANFAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFWOF_B_CHANFAIL_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFWOF));
#endif
    return i_data.extractToRight<USTL_USTLCFWOF_B_CHANFAIL_WOF,
           USTL_USTLCFWOF_B_CHANFAIL_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLCFWOF_B_CHANFAIL_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFAILMASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFAILMASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFAILMASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFAILMASK;
#endif
    return fapi2::getScom(i_target, USTL_USTLFAILMASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFAILMASK(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return fapi2::putScom(i_target, USTL_USTLFAILMASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFAILMASK_RECOVER_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return o_data.insertFromRight<USTL_USTLFAILMASK_RECOVER_ENABLE_MASK,
           USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFAILMASK_RECOVER_ENABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return o_data.insertFromRight<USTL_USTLFAILMASK_RECOVER_ENABLE_MASK,
           USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFAILMASK_RECOVER_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return i_data.extractToRight<USTL_USTLFAILMASK_RECOVER_ENABLE_MASK,
           USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return o_data.insertFromRight<USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK,
           USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return o_data.insertFromRight<USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK,
           USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return i_data.extractToRight<USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK,
           USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return o_data.insertFromRight<USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK,
           USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return o_data.insertFromRight<USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK,
           USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return i_data.extractToRight<USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK,
           USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return o_data.insertFromRight<USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE,
           USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return o_data.insertFromRight<USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE,
           USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFAILMASK));
#endif
    return i_data.extractToRight<USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE,
           USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRMASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRMASK_RW;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRMASK_RW, USTL_USTLFIRMASK_WO_AND, USTL_USTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRMASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRMASK_WO_AND;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRMASK_RW, USTL_USTLFIRMASK_WO_AND, USTL_USTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRMASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRMASK_WO_OR;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRMASK_RW, USTL_USTLFIRMASK_WO_AND, USTL_USTLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRMASK_RW, USTL_USTLFIRMASK_WO_AND, USTL_USTLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK,
           USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRMASK_RW, USTL_USTLFIRMASK_WO_AND, USTL_USTLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK,
           USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRMASK_RW, USTL_USTLFIRMASK_WO_AND, USTL_USTLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK,
           USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLFIRMASK_USTLFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLLOLMASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLLOLMASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLLOLMASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLLOLMASK;
#endif
    return fapi2::getScom(i_target, USTL_USTLLOLMASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLLOLMASK(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLMASK));
#endif
    return fapi2::putScom(i_target, USTL_USTLLOLMASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLMASK));
#endif
    return o_data.insertFromRight<USTL_USTLLOLMASK_RECOVER_ENABLE_MASK,
           USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLMASK));
#endif
    return o_data.insertFromRight<USTL_USTLLOLMASK_RECOVER_ENABLE_MASK,
           USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLLOLMASK_RECOVER_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLMASK));
#endif
    return i_data.extractToRight<USTL_USTLLOLMASK_RECOVER_ENABLE_MASK,
           USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLMASK_RECOVER_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLMASK));
#endif
    return o_data.insertFromRight<USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK,
           USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLMASK));
#endif
    return o_data.insertFromRight<USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK,
           USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLLOLMASK));
#endif
    return i_data.extractToRight<USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK,
           USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access USTL_USTLLOLMASK_CHECKSTOP_ENABLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
