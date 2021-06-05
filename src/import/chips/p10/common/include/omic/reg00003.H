/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00003.H $         */
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

#ifndef __OMIC_REG00003_H_
#define __OMIC_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[MC_OMI_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MC_OMI_FIR_MASK_REG_RW]

//>> GET_[MC_OMI_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MC_OMI_FIR_MASK_REG_RW]

//>> PUT_[MC_OMI_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MC_OMI_FIR_MASK_REG_RW]

//>> PREP_[MC_OMI_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MC_OMI_FIR_MASK_REG_WO_AND]

//>> GET_[MC_OMI_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MC_OMI_FIR_MASK_REG_WO_AND]

//>> PUT_[MC_OMI_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MC_OMI_FIR_MASK_REG_WO_AND]

//>> PREP_[MC_OMI_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MC_OMI_FIR_MASK_REG_WO_OR]

//>> GET_[MC_OMI_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MC_OMI_FIR_MASK_REG_WO_OR]

//>> PUT_[MC_OMI_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MC_OMI_FIR_MASK_REG_WO_OR]


//>> SET_[MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK]

//>> SET_[MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK]

//>> GET_[MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK]

//>> SET_[MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK]

//>> SET_[MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK]

//>> GET_[MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK]

//>> SET_[MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK]

//>> SET_[MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK]

//>> GET_[MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK]

//>> SET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]

//>> SET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]

//>> SET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]

//>> CLEAR_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]

//>> GET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]

//>> GET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]
static inline bool GET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK]

//>> PREP_[CTL_REGS_TX_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_TX_CNTL5_PG]

//>> GET_[CTL_REGS_TX_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL5_PG]

//>> PUT_[CTL_REGS_TX_CNTL5_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_TX_CNTL5_PG]


//>> SET_[CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET]

//>> SET_[CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET]

//>> GET_[CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET]

//>> PREP_[DATASM_REGS_RX_CNTL6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL6_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNTL6_PG]

//>> GET_[DATASM_REGS_RX_CNTL6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL6_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL6_PG]

//>> PUT_[DATASM_REGS_RX_CNTL6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL6_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNTL6_PG]


//>> SET_[DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL6_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]

//>> SET_[DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL6_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]

//>> GET_[DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL6_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]

//>> PREP_[CTL_REGS_RX_MODE17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE17_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE17_PG]

//>> GET_[CTL_REGS_RX_MODE17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE17_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE17_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE17_PG]

//>> PUT_[CTL_REGS_RX_MODE17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE17_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE17_PG]


//>> SET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]

//>> SET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]

//>> GET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]

//>> SET_[CTL_REGS_RX_MODE17_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_THRESH3,
           CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE17_PG_THRESH3]

//>> SET_[CTL_REGS_RX_MODE17_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_THRESH3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_THRESH3,
           CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE17_PG_THRESH3]

//>> GET_[CTL_REGS_RX_MODE17_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE17_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE17_PG_THRESH3,
           CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE17_PG_THRESH3]

//>> SET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]

//>> SET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]

//>> GET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]

//>> SET_[CTL_REGS_RX_MODE17_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_THRESH4,
           CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE17_PG_THRESH4]

//>> SET_[CTL_REGS_RX_MODE17_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_THRESH4,
           CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE17_PG_THRESH4]

//>> GET_[CTL_REGS_RX_MODE17_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE17_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE17_PG_THRESH4,
           CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE17_PG_THRESH4]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
