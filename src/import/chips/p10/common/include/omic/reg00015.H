/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00015.H $         */
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

#ifndef __OMIC_REG00015_H_
#define __OMIC_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[MC_OMI_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MC_OMI_FIR_REG_RW]

//>> GET_[MC_OMI_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MC_OMI_FIR_REG_RW]

//>> PUT_[MC_OMI_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MC_OMI_FIR_REG_RW]

//>> PREP_[MC_OMI_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MC_OMI_FIR_REG_WO_AND]

//>> GET_[MC_OMI_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MC_OMI_FIR_REG_WO_AND]

//>> PUT_[MC_OMI_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MC_OMI_FIR_REG_WO_AND]

//>> PREP_[MC_OMI_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MC_OMI_FIR_REG_WO_OR]

//>> GET_[MC_OMI_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MC_OMI_FIR_REG_WO_OR]

//>> PUT_[MC_OMI_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MC_OMI_FIR_REG_WO_OR]


//>> SET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]

//>> GET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]

//>> GET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]
static inline bool GET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_FATAL_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL0_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_DATA_UE]

//>> SET_[MC_OMI_FIR_REG_DL0_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_DATA_UE]

//>> SET_[MC_OMI_FIR_REG_DL0_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_DATA_UE]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_DATA_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_DATA_UE]

//>> GET_[MC_OMI_FIR_REG_DL0_DATA_UE]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_DATA_UE]

//>> GET_[MC_OMI_FIR_REG_DL0_DATA_UE]
static inline bool GET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_DATA_UE]

//>> SET_[MC_OMI_FIR_REG_DL0_FLIT_CE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_FLIT_CE]

//>> SET_[MC_OMI_FIR_REG_DL0_FLIT_CE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_FLIT_CE]

//>> SET_[MC_OMI_FIR_REG_DL0_FLIT_CE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_FLIT_CE]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_FLIT_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_FLIT_CE]

//>> GET_[MC_OMI_FIR_REG_DL0_FLIT_CE]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_FLIT_CE]

//>> GET_[MC_OMI_FIR_REG_DL0_FLIT_CE]
static inline bool GET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_FLIT_CE]

//>> SET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_CRC_ERROR]

//>> GET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]

//>> GET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]
static inline bool GET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_CRC_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL0_NACK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_NACK]

//>> SET_[MC_OMI_FIR_REG_DL0_NACK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_NACK]

//>> SET_[MC_OMI_FIR_REG_DL0_NACK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_NACK]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_NACK]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_NACK]

//>> GET_[MC_OMI_FIR_REG_DL0_NACK]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_NACK]

//>> GET_[MC_OMI_FIR_REG_DL0_NACK]
static inline bool GET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_NACK]

//>> SET_[MC_OMI_FIR_REG_DL0_X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_X4_MODE]

//>> SET_[MC_OMI_FIR_REG_DL0_X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_X4_MODE]

//>> SET_[MC_OMI_FIR_REG_DL0_X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_X4_MODE]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_X4_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_X4_MODE]

//>> GET_[MC_OMI_FIR_REG_DL0_X4_MODE]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_X4_MODE]

//>> GET_[MC_OMI_FIR_REG_DL0_X4_MODE]
static inline bool GET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_X4_MODE]

//>> SET_[MC_OMI_FIR_REG_DL0_EDPL]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_EDPL]

//>> SET_[MC_OMI_FIR_REG_DL0_EDPL]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_EDPL]

//>> SET_[MC_OMI_FIR_REG_DL0_EDPL]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_EDPL]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_EDPL]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_EDPL]

//>> GET_[MC_OMI_FIR_REG_DL0_EDPL]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_EDPL]

//>> GET_[MC_OMI_FIR_REG_DL0_EDPL]
static inline bool GET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_EDPL]

//>> SET_[MC_OMI_FIR_REG_DL0_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_TIMEOUT]

//>> SET_[MC_OMI_FIR_REG_DL0_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_TIMEOUT]

//>> SET_[MC_OMI_FIR_REG_DL0_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_TIMEOUT]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_TIMEOUT]

//>> GET_[MC_OMI_FIR_REG_DL0_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_TIMEOUT]

//>> GET_[MC_OMI_FIR_REG_DL0_TIMEOUT]
static inline bool GET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_TIMEOUT]

//>> SET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]
static inline bool GET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]
static inline bool GET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ERROR_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]
static inline bool GET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_EDPL_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL0_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_TRAINED]

//>> SET_[MC_OMI_FIR_REG_DL0_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_TRAINED]

//>> SET_[MC_OMI_FIR_REG_DL0_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_TRAINED]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_TRAINED]

//>> GET_[MC_OMI_FIR_REG_DL0_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_TRAINED]

//>> GET_[MC_OMI_FIR_REG_DL0_TRAINED]
static inline bool GET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_TRAINED]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]
static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]
static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]
static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]
static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]
static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]
static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]
static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]

//>> SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]

//>> CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]

//>> GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]
static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7]

//>> SET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]

//>> GET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]

//>> GET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]
static inline bool GET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_FATAL_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL1_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_DATA_UE]

//>> SET_[MC_OMI_FIR_REG_DL1_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_DATA_UE]

//>> SET_[MC_OMI_FIR_REG_DL1_DATA_UE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_DATA_UE]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_DATA_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_DATA_UE]

//>> GET_[MC_OMI_FIR_REG_DL1_DATA_UE]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_DATA_UE]

//>> GET_[MC_OMI_FIR_REG_DL1_DATA_UE]
static inline bool GET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_DATA_UE]

//>> SET_[MC_OMI_FIR_REG_DL1_FLIT_CE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_FLIT_CE]

//>> SET_[MC_OMI_FIR_REG_DL1_FLIT_CE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_FLIT_CE]

//>> SET_[MC_OMI_FIR_REG_DL1_FLIT_CE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_FLIT_CE]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_FLIT_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_FLIT_CE]

//>> GET_[MC_OMI_FIR_REG_DL1_FLIT_CE]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_FLIT_CE]

//>> GET_[MC_OMI_FIR_REG_DL1_FLIT_CE]
static inline bool GET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_FLIT_CE]

//>> SET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_CRC_ERROR]

//>> GET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]

//>> GET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]
static inline bool GET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_CRC_ERROR]

//>> SET_[MC_OMI_FIR_REG_DL1_NACK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_NACK]

//>> SET_[MC_OMI_FIR_REG_DL1_NACK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_NACK]

//>> SET_[MC_OMI_FIR_REG_DL1_NACK]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_NACK]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_NACK]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_NACK]

//>> GET_[MC_OMI_FIR_REG_DL1_NACK]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_NACK]

//>> GET_[MC_OMI_FIR_REG_DL1_NACK]
static inline bool GET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_NACK]

//>> SET_[MC_OMI_FIR_REG_DL1_X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_X4_MODE]

//>> SET_[MC_OMI_FIR_REG_DL1_X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_X4_MODE]

//>> SET_[MC_OMI_FIR_REG_DL1_X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_X4_MODE]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_X4_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_X4_MODE]

//>> GET_[MC_OMI_FIR_REG_DL1_X4_MODE]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_X4_MODE]

//>> GET_[MC_OMI_FIR_REG_DL1_X4_MODE]
static inline bool GET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_X4_MODE]

//>> SET_[MC_OMI_FIR_REG_DL1_EDPL]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_EDPL]

//>> SET_[MC_OMI_FIR_REG_DL1_EDPL]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_EDPL]

//>> SET_[MC_OMI_FIR_REG_DL1_EDPL]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_EDPL]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_EDPL]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_EDPL]

//>> GET_[MC_OMI_FIR_REG_DL1_EDPL]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_EDPL]

//>> GET_[MC_OMI_FIR_REG_DL1_EDPL]
static inline bool GET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_EDPL]

//>> SET_[MC_OMI_FIR_REG_DL1_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_TIMEOUT]

//>> SET_[MC_OMI_FIR_REG_DL1_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_TIMEOUT]

//>> SET_[MC_OMI_FIR_REG_DL1_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_TIMEOUT]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_TIMEOUT]

//>> GET_[MC_OMI_FIR_REG_DL1_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_TIMEOUT]

//>> GET_[MC_OMI_FIR_REG_DL1_TIMEOUT]
static inline bool GET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_TIMEOUT]

//>> SET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]
static inline bool GET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]
static inline bool GET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ERROR_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]

//>> GET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]
static inline bool GET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_EDPL_RETRAIN]

//>> SET_[MC_OMI_FIR_REG_DL1_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_TRAINED]

//>> SET_[MC_OMI_FIR_REG_DL1_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_TRAINED]

//>> SET_[MC_OMI_FIR_REG_DL1_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_TRAINED]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_TRAINED]

//>> GET_[MC_OMI_FIR_REG_DL1_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_TRAINED]

//>> GET_[MC_OMI_FIR_REG_DL1_TRAINED]
static inline bool GET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_TRAINED]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]
static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]
static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]
static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]
static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]
static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]
static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]
static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]

//>> SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]

//>> CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]

//>> GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]
static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7]

//>> SET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]

//>> SET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]

//>> SET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]

//>> CLEAR_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]
static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]

//>> GET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]

//>> GET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]
static inline bool GET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_REG_PERF_MON_WRAPPED]

//>> PREP_[DATASM_REGS_RX_CNT33_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT33_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNT33_PG]

//>> GET_[DATASM_REGS_RX_CNT33_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT33_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT33_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT33_PG]

//>> PUT_[DATASM_REGS_RX_CNT33_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT33_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT33_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNT33_PG]


//>> SET_[DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT33_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1]

//>> SET_[DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT33_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1]

//>> GET_[DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT33_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
