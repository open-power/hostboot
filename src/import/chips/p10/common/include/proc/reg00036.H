/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00036.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __PROC_REG00036_H_
#define __PROC_REG00036_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[NX_PBI_RNG_ST0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_ST0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_RNG_ST0]

//>> GET_[NX_PBI_RNG_ST0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_ST0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST0;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_ST0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_RNG_ST0]

//>> PUT_[NX_PBI_RNG_ST0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_ST0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_ST0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_RNG_ST0]


//>> SET_[NX_PBI_RNG_ST0_REPTEST_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_REPTEST_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_REPTEST_MATCH_TH,
           NX_PBI_RNG_ST0_REPTEST_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST0_REPTEST_MATCH_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_REPTEST_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_REPTEST_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_REPTEST_MATCH_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_REPTEST_MATCH_TH,
           NX_PBI_RNG_ST0_REPTEST_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST0_REPTEST_MATCH_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_REPTEST_MATCH_TH]

//>> GET_[NX_PBI_RNG_ST0_REPTEST_MATCH_TH]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST0_REPTEST_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST0_REPTEST_MATCH_TH,
           NX_PBI_RNG_ST0_REPTEST_MATCH_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST0_REPTEST_MATCH_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST0_REPTEST_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH,
           NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH]

//>> SET_[NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH,
           NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH]

//>> GET_[NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH,
           NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST0_REPTEST_SOFT_FAIL_TH]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE,
           NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE,
           NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE]

//>> GET_[NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE,
           NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE,
           NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE,
           NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE]

//>> GET_[NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE,
           NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH]

//>> GET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH]

//>> GET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH]

//>> GET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH]

//>> SET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH]

//>> GET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST0));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH,
           NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH]

//>> PREP_[NX_PBI_UMAC_STATUS_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_STATUS_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_STATUS_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_UMAC_STATUS_CONTROL]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_STATUS_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_STATUS_CONTROL;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_STATUS_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL]

//>> PUT_[NX_PBI_UMAC_STATUS_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_STATUS_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_STATUS_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_UMAC_STATUS_CONTROL]


//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]

//>> CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]
static inline bool GET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_ENBL]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]

//>> CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]
static inline bool GET_NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_CRB_READS_HALTED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]

//>> CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]
static inline bool GET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_IDLE]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]

//>> CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]
static inline bool GET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_REQUEST]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]

//>> CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]
static inline bool GET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_ACHEIVED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]

//>> CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]
static inline bool GET_NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_QUIESCE_FAILED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]

//>> CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]
static inline bool GET_NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_UMAC_QUIESCED]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]

//>> SET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]

//>> CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]

//>> GET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]
static inline bool GET_NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_STATUS_CONTROL_PASTE_ADDR_ALIGN]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
