/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00001.H $          */
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

#ifndef __MCC_REG00001_H_
#define __MCC_REG00001_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[ATCL_CL_CLSCOM_MCPERF2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCPERF2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCPERF2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ATCL_CL_CLSCOM_MCPERF2]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCPERF2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCPERF2;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCPERF2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2]

//>> PUT_[ATCL_CL_CLSCOM_MCPERF2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCPERF2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCPERF2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ATCL_CL_CLSCOM_MCPERF2]


//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3,
           ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH,
           ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH,
           ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH,
           ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PERF]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PERF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PERF,
           ATCL_CL_CLSCOM_MCPERF2_PERF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PERF]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_PERF]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_PERF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_PERF,
           ATCL_CL_CLSCOM_MCPERF2_PERF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_PERF]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_PERF]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_PERF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_PERF,
           ATCL_CL_CLSCOM_MCPERF2_PERF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_PERF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_PERF]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23,
           ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23,
           ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23,
           ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_RESERVED36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_RESERVED36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_RESERVED36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED36]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG,
           ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG,
           ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG,
           ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL,
           ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN,
           ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN,
           ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN,
           ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_RESERVED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_49]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF,
           ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF,
           ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF,
           ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH,
           ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH,
           ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH,
           ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL,
           ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL,
           ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL,
           ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_RESERVED_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_RESERVED_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_RESERVED_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_RESERVED_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_RESERVED_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_RESERVED_62]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]

//>> SET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]

//>> GET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF2));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES]

//>> PREP_[CRYPTO_DECRYPT_CRYPTOKEY1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_DECRYPT_CRYPTOKEY1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOKEY1A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CRYPTO_DECRYPT_CRYPTOKEY1A]

//>> GET_[CRYPTO_DECRYPT_CRYPTOKEY1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_DECRYPT_CRYPTOKEY1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_DECRYPT_CRYPTOKEY1A;
#endif
    return fapi2::getScom(i_target, CRYPTO_DECRYPT_CRYPTOKEY1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOKEY1A]

//>> PUT_[CRYPTO_DECRYPT_CRYPTOKEY1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_DECRYPT_CRYPTOKEY1A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY1A));
#endif
    return fapi2::putScom(i_target, CRYPTO_DECRYPT_CRYPTOKEY1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CRYPTO_DECRYPT_CRYPTOKEY1A]


//>> SET_[CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY1A));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A,
           CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A]

//>> SET_[CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A]
static inline fapi2::buffer<uint64_t>& SET_CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY1A));
#endif
    return o_data.insertFromRight<CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A,
           CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A]

//>> GET_[CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A]
static inline fapi2::buffer<uint64_t>& GET_CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_DECRYPT_CRYPTOKEY1A));
#endif
    return i_data.extractToRight<CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A,
           CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
