/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00013.H $          */
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

#ifndef __MCC_REG00013_H_
#define __MCC_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[ATCL_CL_CLSCOM_MCPERF0]
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
//<< PREP_[ATCL_CL_CLSCOM_MCPERF0]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0]
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
//<< GET_[ATCL_CL_CLSCOM_MCPERF0]

//>> PUT_[ATCL_CL_CLSCOM_MCPERF0]
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
//<< PUT_[ATCL_CL_CLSCOM_MCPERF0]


//>> SET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_EN_CL_DIS_LIMIT_NSQ]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_EN_AMO_LIMIT_SUM]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_WRBUF_ACTIVE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_SUBCH_COUNT_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_FASTPATH_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CP_WRBUF_RSVD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_EPF_LIMIT]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM,
           ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM,
           ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM,
           ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_SUM]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF0));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_WRAP_MODE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_CL_ACTIVE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HA_RSVD_SEL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_WRBUF_RSVD]

//>> PREP_[USTL_USTLCFG]
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
//<< PREP_[USTL_USTLCFG]

//>> GET_[USTL_USTLCFG]
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
//<< GET_[USTL_USTLCFG]

//>> PUT_[USTL_USTLCFG]
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
//<< PUT_[USTL_USTLCFG]


//>> SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]

//>> SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]

//>> SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]

//>> CLEAR_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]

//>> GET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]

//>> GET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]
static inline bool GET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE]

//>> SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]

//>> SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]

//>> SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]

//>> CLEAR_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]

//>> GET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]

//>> GET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]
static inline bool GET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE]

//>> SET_[USTL_USTLCFG_FAIL_CAPTURE_CONFIG]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_FAIL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_FAIL_CAPTURE_CONFIG]

//>> SET_[USTL_USTLCFG_FAIL_CAPTURE_CONFIG]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_FAIL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_FAIL_CAPTURE_CONFIG]

//>> GET_[USTL_USTLCFG_FAIL_CAPTURE_CONFIG]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_FAIL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_FAIL_CAPTURE_CONFIG]

//>> SET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]

//>> SET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]

//>> SET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]

//>> CLEAR_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]

//>> GET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]

//>> GET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]
static inline bool GET_USTL_USTLCFG_DEFAULT_META_DATA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DEFAULT_META_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DEFAULT_META_DATA_ENABLE]

//>> SET_[USTL_USTLCFG_DEFAULT_META_DATA]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DEFAULT_META_DATA]

//>> SET_[USTL_USTLCFG_DEFAULT_META_DATA]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DEFAULT_META_DATA]

//>> GET_[USTL_USTLCFG_DEFAULT_META_DATA]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_DEFAULT_META_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DEFAULT_META_DATA]

//>> SET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]

//>> SET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]

//>> SET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]

//>> CLEAR_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]

//>> GET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]

//>> GET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]
static inline bool GET_USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_TMPL1_FORCE_MDI_ZERO]

//>> SET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]

//>> SET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]

//>> SET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]

//>> CLEAR_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]

//>> GET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]

//>> GET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]
static inline bool GET_USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE]

//>> SET_[USTL_USTLCFG_LOWLAT_MISS_015_DELAY]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_LOWLAT_MISS_015_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOWLAT_MISS_015_DELAY]

//>> SET_[USTL_USTLCFG_LOWLAT_MISS_015_DELAY]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_LOWLAT_MISS_015_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOWLAT_MISS_015_DELAY]

//>> GET_[USTL_USTLCFG_LOWLAT_MISS_015_DELAY]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_LOWLAT_MISS_015_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LOWLAT_MISS_015_DELAY]

//>> SET_[USTL_USTLCFG_RESERVED_12_16]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_12_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_12_16]

//>> SET_[USTL_USTLCFG_RESERVED_12_16]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_12_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_12_16]

//>> GET_[USTL_USTLCFG_RESERVED_12_16]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_12_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RESERVED_12_16]

//>> SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]

//>> SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]

//>> SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]

//>> CLEAR_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]

//>> GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]

//>> GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]
static inline bool GET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE]

//>> SET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]

//>> SET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]

//>> SET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]

//>> CLEAR_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]

//>> GET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]

//>> GET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]
static inline bool GET_USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_MMIOCNFG_READ_LOL_BLOCK_DISABLE]

//>> SET_[USTL_USTLCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_19]

//>> SET_[USTL_USTLCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_19]

//>> SET_[USTL_USTLCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_19]

//>> CLEAR_[USTL_USTLCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_RESERVED_19]

//>> GET_[USTL_USTLCFG_RESERVED_19]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_RESERVED_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RESERVED_19]

//>> GET_[USTL_USTLCFG_RESERVED_19]
static inline bool GET_USTL_USTLCFG_RESERVED_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RESERVED_19]

//>> SET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]

//>> SET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]

//>> SET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]

//>> CLEAR_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]

//>> GET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]

//>> GET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]
static inline bool GET_USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_SELF_DETECT_DEAD_CYCLE_EN]

//>> SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE]

//>> SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE]

//>> GET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE]

//>> SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]

//>> SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]

//>> SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]

//>> CLEAR_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]

//>> GET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]

//>> GET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]
static inline bool GET_USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_REQUIRE_IDLE]

//>> SET_[USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE]

//>> SET_[USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE]

//>> GET_[USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE]

//>> SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]

//>> SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]

//>> SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]

//>> CLEAR_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]

//>> GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]

//>> GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]
static inline bool GET_USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE]

//>> SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT]

//>> SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT]

//>> GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT]

//>> SET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]

//>> SET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]

//>> SET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]

//>> CLEAR_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]

//>> GET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]

//>> GET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]
static inline bool GET_USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DISABLE_WDF_DM5_REQUESTS]

//>> SET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]

//>> SET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]

//>> SET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]

//>> CLEAR_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]

//>> GET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]

//>> GET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]
static inline bool GET_USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE]

//>> SET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]

//>> SET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]

//>> SET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]

//>> CLEAR_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]

//>> GET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]

//>> GET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]
static inline bool GET_USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE]

//>> SET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]

//>> SET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]

//>> SET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]

//>> CLEAR_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]

//>> GET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]

//>> GET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]
static inline bool GET_USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_FLIT_RATE_DETECT_SAFE_MODE]

//>> SET_[USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD]

//>> SET_[USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD]

//>> GET_[USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_TMPL9_COLD_START_THRESHOLD]

//>> SET_[USTL_USTLCFG_RESERVED_44]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_44]

//>> SET_[USTL_USTLCFG_RESERVED_44]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_44]

//>> SET_[USTL_USTLCFG_RESERVED_44]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RESERVED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_44]

//>> CLEAR_[USTL_USTLCFG_RESERVED_44]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RESERVED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RESERVED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_RESERVED_44]

//>> GET_[USTL_USTLCFG_RESERVED_44]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RESERVED_44]

//>> GET_[USTL_USTLCFG_RESERVED_44]
static inline bool GET_USTL_USTLCFG_RESERVED_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RESERVED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RESERVED_44]

//>> SET_[USTL_USTLCFG_RESERVED_45]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_45]

//>> SET_[USTL_USTLCFG_RESERVED_45]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_45]

//>> SET_[USTL_USTLCFG_RESERVED_45]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_RESERVED_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_RESERVED_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_RESERVED_45]

//>> CLEAR_[USTL_USTLCFG_RESERVED_45]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_RESERVED_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_RESERVED_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_RESERVED_45]

//>> GET_[USTL_USTLCFG_RESERVED_45]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RESERVED_45]

//>> GET_[USTL_USTLCFG_RESERVED_45]
static inline bool GET_USTL_USTLCFG_RESERVED_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_RESERVED_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_RESERVED_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_RESERVED_45]

//>> SET_[USTL_USTLCFG_CFG_WRAP_MODE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CFG_WRAP_MODE]

//>> SET_[USTL_USTLCFG_CFG_WRAP_MODE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CFG_WRAP_MODE]

//>> SET_[USTL_USTLCFG_CFG_WRAP_MODE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CFG_WRAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_CFG_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CFG_WRAP_MODE]

//>> CLEAR_[USTL_USTLCFG_CFG_WRAP_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_CFG_WRAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_CFG_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_CFG_WRAP_MODE]

//>> GET_[USTL_USTLCFG_CFG_WRAP_MODE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CFG_WRAP_MODE]

//>> GET_[USTL_USTLCFG_CFG_WRAP_MODE]
static inline bool GET_USTL_USTLCFG_CFG_WRAP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_CFG_WRAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_CFG_WRAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CFG_WRAP_MODE]

//>> SET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]

//>> SET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]

//>> SET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]

//>> CLEAR_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]

//>> GET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]

//>> GET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]
static inline bool GET_USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_X4_LOL_SPEC_DM6_SLOT131415_EN]

//>> SET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]

//>> SET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]

//>> SET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]

//>> CLEAR_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]

//>> GET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]

//>> GET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]
static inline bool GET_USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CFG_LFSR_LOL_EXIT_MODE]

//>> SET_[USTL_USTLCFG_LOL_LFSR_RATE_SEL]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_LOL_LFSR_RATE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_LFSR_RATE_SEL]

//>> SET_[USTL_USTLCFG_LOL_LFSR_RATE_SEL]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_LOL_LFSR_RATE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_LFSR_RATE_SEL]

//>> GET_[USTL_USTLCFG_LOL_LFSR_RATE_SEL]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_LOL_LFSR_RATE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LOL_LFSR_RATE_SEL]

//>> SET_[USTL_USTLCFG_CS_HW485610_DISABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW485610_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CS_HW485610_DISABLE]

//>> SET_[USTL_USTLCFG_CS_HW485610_DISABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW485610_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CS_HW485610_DISABLE]

//>> GET_[USTL_USTLCFG_CS_HW485610_DISABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW485610_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CS_HW485610_DISABLE]

//>> SET_[USTL_USTLCFG_LOL_CAPTURE_CONFIG]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_LOL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_CAPTURE_CONFIG]

//>> SET_[USTL_USTLCFG_LOL_CAPTURE_CONFIG]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_LOL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_CAPTURE_CONFIG]

//>> GET_[USTL_USTLCFG_LOL_CAPTURE_CONFIG]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_LOL_CAPTURE_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LOL_CAPTURE_CONFIG]

//>> SET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]

//>> SET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]

//>> SET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_LAST_OPENCAPI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]

//>> CLEAR_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_LAST_OPENCAPI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]

//>> GET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]

//>> GET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]
static inline bool GET_USTL_USTLCFG_LAST_OPENCAPI_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_LAST_OPENCAPI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_LAST_OPENCAPI_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LAST_OPENCAPI_ENABLE]

//>> SET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]

//>> SET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]

//>> SET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]

//>> CLEAR_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]

//>> GET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]

//>> GET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]
static inline bool GET_USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_DISABLE_FAILRESP_TO_RMW]

//>> SET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]

//>> SET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]

//>> SET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_PMU_SELECT_FAIL_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]

//>> CLEAR_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_PMU_SELECT_FAIL_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]

//>> GET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]

//>> GET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]
static inline bool GET_USTL_USTLCFG_PMU_SELECT_FAIL_RSP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_PMU_SELECT_FAIL_RSP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_FAIL_RSP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_PMU_SELECT_FAIL_RSP]

//>> SET_[USTL_USTLCFG_PMU_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_ENABLE]

//>> SET_[USTL_USTLCFG_PMU_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_ENABLE]

//>> SET_[USTL_USTLCFG_PMU_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_ENABLE]

//>> CLEAR_[USTL_USTLCFG_PMU_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_PMU_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_PMU_ENABLE]

//>> GET_[USTL_USTLCFG_PMU_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_PMU_ENABLE]

//>> GET_[USTL_USTLCFG_PMU_ENABLE]
static inline bool GET_USTL_USTLCFG_PMU_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_PMU_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_PMU_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_PMU_ENABLE]

//>> SET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]

//>> SET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]

//>> SET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_PMU_SELECT_ALT_PERF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_PMU_SELECT_ALT_PERF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]

//>> CLEAR_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_PMU_SELECT_ALT_PERF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_PMU_SELECT_ALT_PERF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]

//>> GET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]

//>> GET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]
static inline bool GET_USTL_USTLCFG_PMU_SELECT_ALT_PERF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_PMU_SELECT_ALT_PERF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_PMU_SELECT_ALT_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_PMU_SELECT_ALT_PERF]

//>> SET_[USTL_USTLCFG_CS_HW477424_DISABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CS_HW477424_DISABLE]

//>> SET_[USTL_USTLCFG_CS_HW477424_DISABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CS_HW477424_DISABLE]

//>> SET_[USTL_USTLCFG_CS_HW477424_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW477424_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_CS_HW477424_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CS_HW477424_DISABLE]

//>> CLEAR_[USTL_USTLCFG_CS_HW477424_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_CS_HW477424_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_CS_HW477424_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_CS_HW477424_DISABLE]

//>> GET_[USTL_USTLCFG_CS_HW477424_DISABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CS_HW477424_DISABLE]

//>> GET_[USTL_USTLCFG_CS_HW477424_DISABLE]
static inline bool GET_USTL_USTLCFG_CS_HW477424_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_CS_HW477424_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW477424_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CS_HW477424_DISABLE]

//>> SET_[USTL_USTLCFG_CS_HW475333_DISABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CS_HW475333_DISABLE]

//>> SET_[USTL_USTLCFG_CS_HW475333_DISABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CS_HW475333_DISABLE]

//>> SET_[USTL_USTLCFG_CS_HW475333_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_CS_HW475333_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_CS_HW475333_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_CS_HW475333_DISABLE]

//>> CLEAR_[USTL_USTLCFG_CS_HW475333_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_CS_HW475333_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_CS_HW475333_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_CS_HW475333_DISABLE]

//>> GET_[USTL_USTLCFG_CS_HW475333_DISABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CS_HW475333_DISABLE]

//>> GET_[USTL_USTLCFG_CS_HW475333_DISABLE]
static inline bool GET_USTL_USTLCFG_CS_HW475333_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_CS_HW475333_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_CS_HW475333_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_CS_HW475333_DISABLE]

//>> SET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]

//>> SET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.insertFromRight<USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]

//>> SET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.setBit<USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]

//>> CLEAR_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return o_data.clearBit<USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]

//>> GET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.extractToRight<USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]

//>> GET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]
static inline bool GET_USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLCFG));
#endif
    return i_data.getBit<USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLCFG_LOL_DROPOUT_FOR_DL_DEGRADE_DIS]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
