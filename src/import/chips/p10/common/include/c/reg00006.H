/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00006.H $            */
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

#ifndef __C_REG00006_H_
#define __C_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_CERR]
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
//<< PREP_[CPMS_CERR]

//>> GET_[CPMS_CERR]
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
//<< GET_[CPMS_CERR]

//>> PUT_[CPMS_CERR]
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
//<< PUT_[CPMS_CERR]


//>> SET_[CPMS_CERR_L3_PFET_SEQ_ERR]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_L3_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_L3_PFET_SEQ_ERR]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_L3_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_L3_PFET_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_L3_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_L3_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_L3_PFET_SEQ_ERR]

//>> CLEAR_[CPMS_CERR_L3_PFET_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_L3_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_L3_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_L3_PFET_SEQ_ERR]

//>> GET_[CPMS_CERR_L3_PFET_SEQ_ERR]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_L3_PFET_SEQ_ERR]

//>> GET_[CPMS_CERR_L3_PFET_SEQ_ERR]
static inline bool GET_CPMS_CERR_L3_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_L3_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_L3_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_L3_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_CL2_PFET_SEQ_ERR]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CL2_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_CL2_PFET_SEQ_ERR]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CL2_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_CL2_PFET_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CL2_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_CL2_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CL2_PFET_SEQ_ERR]

//>> CLEAR_[CPMS_CERR_CL2_PFET_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_CL2_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_CL2_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_CL2_PFET_SEQ_ERR]

//>> GET_[CPMS_CERR_CL2_PFET_SEQ_ERR]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_CL2_PFET_SEQ_ERR]

//>> GET_[CPMS_CERR_CL2_PFET_SEQ_ERR]
static inline bool GET_CPMS_CERR_CL2_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_CL2_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_CL2_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_CL2_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_MMA_PFET_SEQ_ERR]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_MMA_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_MMA_PFET_SEQ_ERR]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_MMA_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_MMA_PFET_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_MMA_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_MMA_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_MMA_PFET_SEQ_ERR]

//>> CLEAR_[CPMS_CERR_MMA_PFET_SEQ_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_MMA_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_MMA_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_MMA_PFET_SEQ_ERR]

//>> GET_[CPMS_CERR_MMA_PFET_SEQ_ERR]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_MMA_PFET_SEQ_ERR]

//>> GET_[CPMS_CERR_MMA_PFET_SEQ_ERR]
static inline bool GET_CPMS_CERR_MMA_PFET_SEQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_MMA_PFET_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_MMA_PFET_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_MMA_PFET_SEQ_ERR]

//>> SET_[CPMS_CERR_DDS_ERR]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_DDS_ERR]

//>> SET_[CPMS_CERR_DDS_ERR]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_DDS_ERR]

//>> SET_[CPMS_CERR_DDS_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_DDS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_DDS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_DDS_ERR]

//>> CLEAR_[CPMS_CERR_DDS_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_DDS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_DDS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_DDS_ERR]

//>> GET_[CPMS_CERR_DDS_ERR]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_DDS_ERR]

//>> GET_[CPMS_CERR_DDS_ERR]
static inline bool GET_CPMS_CERR_DDS_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_DDS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_DDS_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_DDS_ERR]

//>> SET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]

//>> SET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]

//>> SET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_L3_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_L3_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]

//>> CLEAR_[CPMS_CERR_L3_CLOCK_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_L3_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_L3_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_L3_CLOCK_SYNC_ERR]

//>> GET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]

//>> GET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]
static inline bool GET_CPMS_CERR_L3_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_L3_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_L3_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_L3_CLOCK_SYNC_ERR]

//>> SET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]

//>> SET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]

//>> SET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CL2_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_CL2_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]

//>> CLEAR_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_CL2_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_CL2_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]

//>> GET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]

//>> GET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]
static inline bool GET_CPMS_CERR_CL2_CLOCK_SYNC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_CL2_CLOCK_SYNC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_CL2_CLOCK_SYNC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_CL2_CLOCK_SYNC_ERR]

//>> SET_[CPMS_CERR_DPT_ACCESS_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_DPT_ACCESS_ERROR]

//>> SET_[CPMS_CERR_DPT_ACCESS_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_DPT_ACCESS_ERROR]

//>> SET_[CPMS_CERR_DPT_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_DPT_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_DPT_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_DPT_ACCESS_ERROR]

//>> CLEAR_[CPMS_CERR_DPT_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_DPT_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_DPT_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_DPT_ACCESS_ERROR]

//>> GET_[CPMS_CERR_DPT_ACCESS_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_DPT_ACCESS_ERROR]

//>> GET_[CPMS_CERR_DPT_ACCESS_ERROR]
static inline bool GET_CPMS_CERR_DPT_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_DPT_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_DPT_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_DPT_ACCESS_ERROR]

//>> SET_[CPMS_CERR_PROXY_UNDERFLOW]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PROXY_UNDERFLOW]

//>> SET_[CPMS_CERR_PROXY_UNDERFLOW]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PROXY_UNDERFLOW]

//>> SET_[CPMS_CERR_PROXY_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PROXY_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_PROXY_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PROXY_UNDERFLOW]

//>> CLEAR_[CPMS_CERR_PROXY_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_PROXY_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_PROXY_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_PROXY_UNDERFLOW]

//>> GET_[CPMS_CERR_PROXY_UNDERFLOW]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_PROXY_UNDERFLOW]

//>> GET_[CPMS_CERR_PROXY_UNDERFLOW]
static inline bool GET_CPMS_CERR_PROXY_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_PROXY_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_PROXY_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_PROXY_UNDERFLOW]

//>> SET_[CPMS_CERR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PITCH_SATURATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_PITCH_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PITCH_SATURATED]

//>> SET_[CPMS_CERR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PITCH_SATURATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_PITCH_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PITCH_SATURATED]

//>> SET_[CPMS_CERR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PITCH_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_PITCH_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PITCH_SATURATED]

//>> CLEAR_[CPMS_CERR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_PITCH_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_PITCH_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_PITCH_SATURATED]

//>> GET_[CPMS_CERR_PITCH_SATURATED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_PITCH_SATURATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_PITCH_SATURATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_PITCH_SATURATED]

//>> GET_[CPMS_CERR_PITCH_SATURATED]
static inline bool GET_CPMS_CERR_PITCH_SATURATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_PITCH_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_PITCH_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_PITCH_SATURATED]

//>> SET_[CPMS_CERR_FTC_DEBUG_EVENT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_FTC_DEBUG_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_FTC_DEBUG_EVENT]

//>> SET_[CPMS_CERR_FTC_DEBUG_EVENT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_FTC_DEBUG_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_FTC_DEBUG_EVENT]

//>> GET_[CPMS_CERR_FTC_DEBUG_EVENT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_FTC_DEBUG_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_FTC_DEBUG_EVENT]

//>> SET_[CPMS_CERR_CCFG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CCFG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_CCFG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_CCFG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CCFG_PARITY_ERR]

//>> SET_[CPMS_CERR_CCFG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CCFG_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_CCFG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_CCFG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CCFG_PARITY_ERR]

//>> SET_[CPMS_CERR_CCFG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_CCFG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_CCFG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_CCFG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_CCFG_PARITY_ERR]

//>> CLEAR_[CPMS_CERR_CCFG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_CCFG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_CCFG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_CCFG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_CCFG_PARITY_ERR]

//>> GET_[CPMS_CERR_CCFG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_CCFG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_CCFG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_CCFG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_CCFG_PARITY_ERR]

//>> GET_[CPMS_CERR_CCFG_PARITY_ERR]
static inline bool GET_CPMS_CERR_CCFG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_CCFG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_CCFG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_CCFG_PARITY_ERR]

//>> SET_[CPMS_CERR_RVRM_DROPOUT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_RVRM_DROPOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_RVRM_DROPOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_RVRM_DROPOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_RVRM_DROPOUT]

//>> SET_[CPMS_CERR_RVRM_DROPOUT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_RVRM_DROPOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_RVRM_DROPOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_RVRM_DROPOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_RVRM_DROPOUT]

//>> SET_[CPMS_CERR_RVRM_DROPOUT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_RVRM_DROPOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_RVRM_DROPOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_RVRM_DROPOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_RVRM_DROPOUT]

//>> CLEAR_[CPMS_CERR_RVRM_DROPOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_RVRM_DROPOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_RVRM_DROPOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_RVRM_DROPOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_RVRM_DROPOUT]

//>> GET_[CPMS_CERR_RVRM_DROPOUT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_RVRM_DROPOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_RVRM_DROPOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_RVRM_DROPOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_RVRM_DROPOUT]

//>> GET_[CPMS_CERR_RVRM_DROPOUT]
static inline bool GET_CPMS_CERR_RVRM_DROPOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_RVRM_DROPOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_RVRM_DROPOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_RVRM_DROPOUT]

//>> SET_[CPMS_CERR_PITCH_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PITCH_UPDATE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_PITCH_UPDATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_PITCH_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PITCH_UPDATE_ERR]

//>> SET_[CPMS_CERR_PITCH_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PITCH_UPDATE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_PITCH_UPDATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_PITCH_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PITCH_UPDATE_ERR]

//>> SET_[CPMS_CERR_PITCH_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_PITCH_UPDATE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_PITCH_UPDATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_PITCH_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_PITCH_UPDATE_ERR]

//>> CLEAR_[CPMS_CERR_PITCH_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_PITCH_UPDATE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_PITCH_UPDATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_PITCH_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_PITCH_UPDATE_ERR]

//>> GET_[CPMS_CERR_PITCH_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_PITCH_UPDATE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_PITCH_UPDATE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_PITCH_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_PITCH_UPDATE_ERR]

//>> GET_[CPMS_CERR_PITCH_UPDATE_ERR]
static inline bool GET_CPMS_CERR_PITCH_UPDATE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_PITCH_UPDATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_PITCH_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_PITCH_UPDATE_ERR]

//>> SET_[CPMS_CERR_SPARE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_SPARE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_SPARE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CERR_SPARE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_SPARE_ERR]

//>> SET_[CPMS_CERR_SPARE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_SPARE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.insertFromRight<CPMS_CERR_SPARE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CERR_SPARE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_SPARE_ERR]

//>> SET_[CPMS_CERR_SPARE_ERR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CERR_SPARE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.setBit<CPMS_CERR_SPARE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CERR_SPARE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CERR_SPARE_ERR]

//>> CLEAR_[CPMS_CERR_SPARE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CERR_SPARE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return o_data.clearBit<CPMS_CERR_SPARE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CERR_SPARE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CERR_SPARE_ERR]

//>> GET_[CPMS_CERR_SPARE_ERR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CERR_SPARE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.extractToRight<CPMS_CERR_SPARE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CERR_SPARE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_SPARE_ERR]

//>> GET_[CPMS_CERR_SPARE_ERR]
static inline bool GET_CPMS_CERR_SPARE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_CERR));
#endif
    return i_data.getBit<CPMS_CERR_SPARE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CERR_SPARE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CERR_SPARE_ERR]

//>> PREP_[CPMS_CUCR]
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
//<< PREP_[CPMS_CUCR]

//>> GET_[CPMS_CUCR]
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
//<< GET_[CPMS_CUCR]

//>> PUT_[CPMS_CUCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CUCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_CUCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CUCR]

//>> PREP_[CPMS_CUCR_SCOM2]
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
//<< PREP_[CPMS_CUCR_SCOM2]

//>> GET_[CPMS_CUCR_SCOM2]
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
//<< GET_[CPMS_CUCR_SCOM2]

//>> PUT_[CPMS_CUCR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CUCR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_CUCR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CUCR_SCOM2]

//>> PREP_[CPMS_CUCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CUCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CUCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_CUCR_WO_CLEAR]

//>> GET_[CPMS_CUCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CUCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CUCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_CUCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_CUCR_WO_CLEAR]

//>> PUT_[CPMS_CUCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CUCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_CUCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CUCR_WO_CLEAR]


//>> SET_[CPMS_CUCR_ENABLE_CORE_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_ENABLE_CORE_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_ENABLE_CORE_SHADOW]

//>> SET_[CPMS_CUCR_ENABLE_CORE_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_ENABLE_CORE_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_ENABLE_CORE_SHADOW]

//>> SET_[CPMS_CUCR_ENABLE_CORE_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_ENABLE_CORE_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_ENABLE_CORE_SHADOW]

//>> CLEAR_[CPMS_CUCR_ENABLE_CORE_SHADOW]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_ENABLE_CORE_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_ENABLE_CORE_SHADOW]

//>> GET_[CPMS_CUCR_ENABLE_CORE_SHADOW]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_ENABLE_CORE_SHADOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_ENABLE_CORE_SHADOW]

//>> GET_[CPMS_CUCR_ENABLE_CORE_SHADOW]
static inline bool GET_CPMS_CUCR_ENABLE_CORE_SHADOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_ENABLE_CORE_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_ENABLE_CORE_SHADOW]

//>> SET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_ENABLE_CORE_SAMPLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]

//>> SET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SAMPLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_ENABLE_CORE_SAMPLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]

//>> SET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_ENABLE_CORE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]

//>> CLEAR_[CPMS_CUCR_ENABLE_CORE_SAMPLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_ENABLE_CORE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_ENABLE_CORE_SAMPLE]

//>> GET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_ENABLE_CORE_SAMPLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]

//>> GET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]
static inline bool GET_CPMS_CUCR_ENABLE_CORE_SAMPLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_ENABLE_CORE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_ENABLE_CORE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_ENABLE_CORE_SAMPLE]

//>> SET_[CPMS_CUCR_DPT_PER_THREAD_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_PER_THREAD_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_DPT_PER_THREAD_MODE]

//>> SET_[CPMS_CUCR_DPT_PER_THREAD_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_PER_THREAD_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_PER_THREAD_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_DPT_PER_THREAD_MODE]

//>> SET_[CPMS_CUCR_DPT_PER_THREAD_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_DPT_PER_THREAD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_DPT_PER_THREAD_MODE]

//>> CLEAR_[CPMS_CUCR_DPT_PER_THREAD_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_DPT_PER_THREAD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_DPT_PER_THREAD_MODE]

//>> GET_[CPMS_CUCR_DPT_PER_THREAD_MODE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_DPT_PER_THREAD_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_DPT_PER_THREAD_MODE]

//>> GET_[CPMS_CUCR_DPT_PER_THREAD_MODE]
static inline bool GET_CPMS_CUCR_DPT_PER_THREAD_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_DPT_PER_THREAD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_DPT_PER_THREAD_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_DPT_PER_THREAD_MODE]

//>> SET_[CPMS_CUCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_SPARE,
           CPMS_CUCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_SPARE]

//>> SET_[CPMS_CUCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_SPARE,
           CPMS_CUCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_SPARE]

//>> GET_[CPMS_CUCR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_SPARE,
           CPMS_CUCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_SPARE]

//>> SET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]

//>> SET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]

//>> SET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]

//>> CLEAR_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]

//>> GET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]

//>> GET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]
static inline bool GET_CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE]

//>> SET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_STOP01_SAMPLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]

//>> SET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_STOP01_SAMPLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]

//>> SET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_STOP01_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]

//>> CLEAR_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_STOP01_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]

//>> GET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_STOP01_SAMPLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]

//>> GET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]
static inline bool GET_CPMS_CUCR_STOP01_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_STOP01_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_STOP01_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_STOP01_SAMPLE_ENABLE]

//>> SET_[CPMS_CUCR_REFRESH_FTC_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_FTC_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_FTC_SHADOW]

//>> SET_[CPMS_CUCR_REFRESH_FTC_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_FTC_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_FTC_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_FTC_SHADOW]

//>> SET_[CPMS_CUCR_REFRESH_FTC_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_REFRESH_FTC_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_FTC_SHADOW]

//>> CLEAR_[CPMS_CUCR_REFRESH_FTC_SHADOW]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_REFRESH_FTC_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_REFRESH_FTC_SHADOW]

//>> GET_[CPMS_CUCR_REFRESH_FTC_SHADOW]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_REFRESH_FTC_SHADOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_REFRESH_FTC_SHADOW]

//>> GET_[CPMS_CUCR_REFRESH_FTC_SHADOW]
static inline bool GET_CPMS_CUCR_REFRESH_FTC_SHADOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_REFRESH_FTC_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_REFRESH_FTC_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_REFRESH_FTC_SHADOW]

//>> SET_[CPMS_CUCR_REFRESH_PP_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_PP_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_PP_SHADOW]

//>> SET_[CPMS_CUCR_REFRESH_PP_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_PP_SHADOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_PP_SHADOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_PP_SHADOW]

//>> SET_[CPMS_CUCR_REFRESH_PP_SHADOW]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_REFRESH_PP_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_PP_SHADOW]

//>> CLEAR_[CPMS_CUCR_REFRESH_PP_SHADOW]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_REFRESH_PP_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_REFRESH_PP_SHADOW]

//>> GET_[CPMS_CUCR_REFRESH_PP_SHADOW]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_REFRESH_PP_SHADOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_REFRESH_PP_SHADOW]

//>> GET_[CPMS_CUCR_REFRESH_PP_SHADOW]
static inline bool GET_CPMS_CUCR_REFRESH_PP_SHADOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_REFRESH_PP_SHADOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_REFRESH_PP_SHADOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_REFRESH_PP_SHADOW]

//>> SET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_DPT_SETTINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]

//>> SET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_DPT_SETTINGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_REFRESH_DPT_SETTINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]

//>> SET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_REFRESH_DPT_SETTINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]

//>> CLEAR_[CPMS_CUCR_REFRESH_DPT_SETTINGS]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_REFRESH_DPT_SETTINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_REFRESH_DPT_SETTINGS]

//>> GET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_REFRESH_DPT_SETTINGS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]

//>> GET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]
static inline bool GET_CPMS_CUCR_REFRESH_DPT_SETTINGS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_REFRESH_DPT_SETTINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_REFRESH_DPT_SETTINGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_REFRESH_DPT_SETTINGS]

//>> SET_[CPMS_CUCR_INDUCED_DROOP_COUNT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_INDUCED_DROOP_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_INDUCED_DROOP_COUNT,
           CPMS_CUCR_INDUCED_DROOP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_INDUCED_DROOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_INDUCED_DROOP_COUNT]

//>> SET_[CPMS_CUCR_INDUCED_DROOP_COUNT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_INDUCED_DROOP_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_INDUCED_DROOP_COUNT,
           CPMS_CUCR_INDUCED_DROOP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_INDUCED_DROOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_INDUCED_DROOP_COUNT]

//>> GET_[CPMS_CUCR_INDUCED_DROOP_COUNT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_INDUCED_DROOP_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_INDUCED_DROOP_COUNT,
           CPMS_CUCR_INDUCED_DROOP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_INDUCED_DROOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_INDUCED_DROOP_COUNT]

//>> SET_[CPMS_CUCR_PCB_SKEW_ADJ]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PCB_SKEW_ADJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PCB_SKEW_ADJ,
           CPMS_CUCR_PCB_SKEW_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_PCB_SKEW_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_PCB_SKEW_ADJ]

//>> SET_[CPMS_CUCR_PCB_SKEW_ADJ]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PCB_SKEW_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PCB_SKEW_ADJ,
           CPMS_CUCR_PCB_SKEW_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_PCB_SKEW_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_PCB_SKEW_ADJ]

//>> GET_[CPMS_CUCR_PCB_SKEW_ADJ]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_PCB_SKEW_ADJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_PCB_SKEW_ADJ,
           CPMS_CUCR_PCB_SKEW_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_PCB_SKEW_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_PCB_SKEW_ADJ]

//>> SET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FDCR_UPDATE_INPROGRESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]

//>> SET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FDCR_UPDATE_INPROGRESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]

//>> SET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_FDCR_UPDATE_INPROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]

//>> CLEAR_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_FDCR_UPDATE_INPROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]

//>> GET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_FDCR_UPDATE_INPROGRESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]

//>> GET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]
static inline bool GET_CPMS_CUCR_FDCR_UPDATE_INPROGRESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_FDCR_UPDATE_INPROGRESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_FDCR_UPDATE_INPROGRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_FDCR_UPDATE_INPROGRESS]

//>> SET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]

//>> SET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]

//>> SET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]

//>> CLEAR_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]

//>> GET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]

//>> GET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]
static inline bool GET_CPMS_CUCR_CORE_SAMPLE_ENABLED_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_CORE_SAMPLE_ENABLED_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_CORE_SAMPLE_ENABLED_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_CORE_SAMPLE_ENABLED_LT]

//>> SET_[CPMS_CUCR_FTC_SHADOW_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FTC_SHADOW_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FTC_SHADOW_STATE,
           CPMS_CUCR_FTC_SHADOW_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_FTC_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_FTC_SHADOW_STATE]

//>> SET_[CPMS_CUCR_FTC_SHADOW_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FTC_SHADOW_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FTC_SHADOW_STATE,
           CPMS_CUCR_FTC_SHADOW_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_FTC_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_FTC_SHADOW_STATE]

//>> GET_[CPMS_CUCR_FTC_SHADOW_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_FTC_SHADOW_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_FTC_SHADOW_STATE,
           CPMS_CUCR_FTC_SHADOW_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_FTC_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_FTC_SHADOW_STATE]

//>> SET_[CPMS_CUCR_FTC_SHADOW_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FTC_SHADOW_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FTC_SHADOW_PENDING,
           CPMS_CUCR_FTC_SHADOW_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_FTC_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_FTC_SHADOW_PENDING]

//>> SET_[CPMS_CUCR_FTC_SHADOW_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_FTC_SHADOW_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_FTC_SHADOW_PENDING,
           CPMS_CUCR_FTC_SHADOW_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_FTC_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_FTC_SHADOW_PENDING]

//>> GET_[CPMS_CUCR_FTC_SHADOW_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_FTC_SHADOW_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_FTC_SHADOW_PENDING,
           CPMS_CUCR_FTC_SHADOW_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_FTC_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_FTC_SHADOW_PENDING]

//>> SET_[CPMS_CUCR_PP_SHADOW_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PP_SHADOW_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PP_SHADOW_STATE,
           CPMS_CUCR_PP_SHADOW_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_PP_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_PP_SHADOW_STATE]

//>> SET_[CPMS_CUCR_PP_SHADOW_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PP_SHADOW_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PP_SHADOW_STATE,
           CPMS_CUCR_PP_SHADOW_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_PP_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_PP_SHADOW_STATE]

//>> GET_[CPMS_CUCR_PP_SHADOW_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_PP_SHADOW_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_PP_SHADOW_STATE,
           CPMS_CUCR_PP_SHADOW_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_PP_SHADOW_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_PP_SHADOW_STATE]

//>> SET_[CPMS_CUCR_PP_SHADOW_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PP_SHADOW_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PP_SHADOW_PENDING,
           CPMS_CUCR_PP_SHADOW_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_PP_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_PP_SHADOW_PENDING]

//>> SET_[CPMS_CUCR_PP_SHADOW_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_PP_SHADOW_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_PP_SHADOW_PENDING,
           CPMS_CUCR_PP_SHADOW_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_PP_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_PP_SHADOW_PENDING]

//>> GET_[CPMS_CUCR_PP_SHADOW_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_PP_SHADOW_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_PP_SHADOW_PENDING,
           CPMS_CUCR_PP_SHADOW_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_PP_SHADOW_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_PP_SHADOW_PENDING]

//>> SET_[CPMS_CUCR_DPT_UPDATE_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_UPDATE_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_UPDATE_STATE,
           CPMS_CUCR_DPT_UPDATE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_DPT_UPDATE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_DPT_UPDATE_STATE]

//>> SET_[CPMS_CUCR_DPT_UPDATE_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_UPDATE_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_UPDATE_STATE,
           CPMS_CUCR_DPT_UPDATE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_DPT_UPDATE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_DPT_UPDATE_STATE]

//>> GET_[CPMS_CUCR_DPT_UPDATE_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_DPT_UPDATE_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_DPT_UPDATE_STATE,
           CPMS_CUCR_DPT_UPDATE_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_DPT_UPDATE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_DPT_UPDATE_STATE]

//>> SET_[CPMS_CUCR_DPT_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_UPDATE_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_UPDATE_PENDING,
           CPMS_CUCR_DPT_UPDATE_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_DPT_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_DPT_UPDATE_PENDING]

//>> SET_[CPMS_CUCR_DPT_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_DPT_UPDATE_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_DPT_UPDATE_PENDING,
           CPMS_CUCR_DPT_UPDATE_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_DPT_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_DPT_UPDATE_PENDING]

//>> GET_[CPMS_CUCR_DPT_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_DPT_UPDATE_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_DPT_UPDATE_PENDING,
           CPMS_CUCR_DPT_UPDATE_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_DPT_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_DPT_UPDATE_PENDING]

//>> SET_[CPMS_CUCR_CORE_REFRESH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_REFRESH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_REFRESH_ACTIVE,
           CPMS_CUCR_CORE_REFRESH_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_CORE_REFRESH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_CORE_REFRESH_ACTIVE]

//>> SET_[CPMS_CUCR_CORE_REFRESH_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_CORE_REFRESH_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_CORE_REFRESH_ACTIVE,
           CPMS_CUCR_CORE_REFRESH_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_CORE_REFRESH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_CORE_REFRESH_ACTIVE]

//>> GET_[CPMS_CUCR_CORE_REFRESH_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_CORE_REFRESH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_CORE_REFRESH_ACTIVE,
           CPMS_CUCR_CORE_REFRESH_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_CORE_REFRESH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_CORE_REFRESH_ACTIVE]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_DATA_TYPE1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_DATA_TYPE1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]

//>> GET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_DATA_TYPE1_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]

//>> GET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]
static inline bool GET_CPMS_CUCR_QME_DATA_TYPE1_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_DATA_TYPE1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_DATA_TYPE1_PENDING]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_DATA_TYPE2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_DATA_TYPE2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]

//>> GET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_DATA_TYPE2_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]

//>> GET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]
static inline bool GET_CPMS_CUCR_QME_DATA_TYPE2_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_DATA_TYPE2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_DATA_TYPE2_PENDING]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_DATA_TYPE3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]

//>> SET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_DATA_TYPE3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_DATA_TYPE3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]

//>> GET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_DATA_TYPE3_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]

//>> GET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]
static inline bool GET_CPMS_CUCR_QME_DATA_TYPE3_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_DATA_TYPE3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_DATA_TYPE3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_DATA_TYPE3_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]
static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]
static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]
static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]
static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]
static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]
static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]
static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]

//>> SET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]

//>> CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]

//>> GET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]
static inline bool GET_CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CUCR, CPMS_CUCR_SCOM2, CPMS_CUCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING]

//>> PREP_[CPMS_DMSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DMSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DMSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DMSR]

//>> GET_[CPMS_DMSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DMSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DMSR;
#endif
    return fapi2::getScom(i_target, CPMS_DMSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DMSR]

//>> PUT_[CPMS_DMSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DMSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DMSR));
#endif
    return fapi2::putScom(i_target, CPMS_DMSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DMSR]


//>> SET_[CPMS_DMSR_0_COUNT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DMSR_0_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DMSR));
#endif
    return o_data.insertFromRight<CPMS_DMSR_0_COUNT,
           CPMS_DMSR_0_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DMSR_0_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DMSR_0_COUNT]

//>> SET_[CPMS_DMSR_0_COUNT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DMSR_0_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DMSR));
#endif
    return o_data.insertFromRight<CPMS_DMSR_0_COUNT,
           CPMS_DMSR_0_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DMSR_0_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DMSR_0_COUNT]

//>> GET_[CPMS_DMSR_0_COUNT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DMSR_0_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DMSR));
#endif
    return i_data.extractToRight<CPMS_DMSR_0_COUNT,
           CPMS_DMSR_0_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DMSR_0_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DMSR_0_COUNT]

//>> SET_[CPMS_DMSR_1_COUNT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DMSR_1_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DMSR));
#endif
    return o_data.insertFromRight<CPMS_DMSR_1_COUNT,
           CPMS_DMSR_1_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DMSR_1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DMSR_1_COUNT]

//>> SET_[CPMS_DMSR_1_COUNT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DMSR_1_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DMSR));
#endif
    return o_data.insertFromRight<CPMS_DMSR_1_COUNT,
           CPMS_DMSR_1_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DMSR_1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DMSR_1_COUNT]

//>> GET_[CPMS_DMSR_1_COUNT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DMSR_1_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DMSR));
#endif
    return i_data.extractToRight<CPMS_DMSR_1_COUNT,
           CPMS_DMSR_1_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DMSR_1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DMSR_1_COUNT]

//>> PREP_[CPMS_DPPR]
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
//<< PREP_[CPMS_DPPR]

//>> GET_[CPMS_DPPR]
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
//<< GET_[CPMS_DPPR]

//>> PUT_[CPMS_DPPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPPR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_DPPR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DPPR]

//>> PREP_[CPMS_DPPR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DPPR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DPPR_WO_CLEAR]

//>> GET_[CPMS_DPPR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DPPR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_DPPR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DPPR_WO_CLEAR]

//>> PUT_[CPMS_DPPR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPPR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_DPPR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DPPR_WO_CLEAR]

//>> PREP_[CPMS_DPPR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DPPR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DPPR_WO_OR]

//>> GET_[CPMS_DPPR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DPPR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPPR_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_DPPR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DPPR_WO_OR]

//>> PUT_[CPMS_DPPR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPPR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_DPPR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DPPR_WO_OR]


//>> SET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]

//>> SET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]

//>> SET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]

//>> CLEAR_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]

//>> GET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]

//>> GET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]
static inline bool GET_CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE]

//>> SET_[CPMS_DPPR_PTSR_EVENT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PTSR_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PTSR_EVENT_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_PTSR_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PTSR_EVENT_SELECT]

//>> SET_[CPMS_DPPR_PTSR_EVENT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PTSR_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PTSR_EVENT_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_PTSR_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PTSR_EVENT_SELECT]

//>> SET_[CPMS_DPPR_PTSR_EVENT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PTSR_EVENT_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_PTSR_EVENT_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_PTSR_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PTSR_EVENT_SELECT]

//>> CLEAR_[CPMS_DPPR_PTSR_EVENT_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_PTSR_EVENT_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_PTSR_EVENT_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_PTSR_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_PTSR_EVENT_SELECT]

//>> GET_[CPMS_DPPR_PTSR_EVENT_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PTSR_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_PTSR_EVENT_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_PTSR_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PTSR_EVENT_SELECT]

//>> GET_[CPMS_DPPR_PTSR_EVENT_SELECT]
static inline bool GET_CPMS_DPPR_PTSR_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_PTSR_EVENT_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_PTSR_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PTSR_EVENT_SELECT]

//>> SET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_ENERGY_PROXY_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_ENERGY_PROXY_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_ENERGY_PROXY_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]

//>> SET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_ENERGY_PROXY_RESET_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_ENERGY_PROXY_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_ENERGY_PROXY_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]

//>> SET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_ENERGY_PROXY_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_ENERGY_PROXY_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_ENERGY_PROXY_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]

//>> CLEAR_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_ENERGY_PROXY_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_ENERGY_PROXY_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_ENERGY_PROXY_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]

//>> GET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_ENERGY_PROXY_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_ENERGY_PROXY_RESET_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_ENERGY_PROXY_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]

//>> GET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]
static inline bool GET_CPMS_DPPR_ENERGY_PROXY_RESET_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_ENERGY_PROXY_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_ENERGY_PROXY_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_ENERGY_PROXY_RESET_MODE]

//>> SET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_THROTTLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_PIL_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]

//>> SET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_THROTTLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PIL_THROTTLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_PIL_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]

//>> SET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PIL_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_PIL_THROTTLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_PIL_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]

//>> CLEAR_[CPMS_DPPR_PIL_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_PIL_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_PIL_THROTTLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_PIL_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_PIL_THROTTLE_ENABLE]

//>> GET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PIL_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_PIL_THROTTLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_PIL_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]

//>> GET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]
static inline bool GET_CPMS_DPPR_PIL_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_PIL_THROTTLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_PIL_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PIL_THROTTLE_ENABLE]

//>> SET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_THROTTLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]

//>> SET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_THROTTLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_THROTTLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]

//>> SET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_THROTTLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_OCP_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]

//>> CLEAR_[CPMS_DPPR_OCP_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_THROTTLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_OCP_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_OCP_THROTTLE_ENABLE]

//>> GET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_THROTTLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]

//>> GET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]
static inline bool GET_CPMS_DPPR_OCP_THROTTLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_THROTTLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_OCP_THROTTLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_THROTTLE_ENABLE]

//>> SET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_INTERRUPT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]

//>> SET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_INTERRUPT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_INTERRUPT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]

//>> SET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_OCP_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]

//>> CLEAR_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_OCP_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]

//>> GET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_INTERRUPT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]

//>> GET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]
static inline bool GET_CPMS_DPPR_OCP_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_OCP_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_INTERRUPT_ENABLE]

//>> SET_[CPMS_DPPR_OCP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_ENABLE]

//>> SET_[CPMS_DPPR_OCP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_ENABLE]

//>> SET_[CPMS_DPPR_OCP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_ENABLE]

//>> CLEAR_[CPMS_DPPR_OCP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_OCP_ENABLE]

//>> GET_[CPMS_DPPR_OCP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_ENABLE]

//>> GET_[CPMS_DPPR_OCP_ENABLE]
static inline bool GET_CPMS_DPPR_OCP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_OCP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_ENABLE]

//>> SET_[CPMS_DPPR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_SPARE,
           CPMS_DPPR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_SPARE]

//>> SET_[CPMS_DPPR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_SPARE,
           CPMS_DPPR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_SPARE]

//>> GET_[CPMS_DPPR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_SPARE,
           CPMS_DPPR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_SPARE]

//>> SET_[CPMS_DPPR_PP0_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PP0_THRESH_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PP0_THRESH_SCALE,
           CPMS_DPPR_PP0_THRESH_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_PP0_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PP0_THRESH_SCALE]

//>> SET_[CPMS_DPPR_PP0_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PP0_THRESH_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PP0_THRESH_SCALE,
           CPMS_DPPR_PP0_THRESH_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_PP0_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PP0_THRESH_SCALE]

//>> GET_[CPMS_DPPR_PP0_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PP0_THRESH_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_PP0_THRESH_SCALE,
           CPMS_DPPR_PP0_THRESH_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_PP0_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PP0_THRESH_SCALE]

//>> SET_[CPMS_DPPR_PP0_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PP0_THRESH_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PP0_THRESH_VALUE,
           CPMS_DPPR_PP0_THRESH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_PP0_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PP0_THRESH_VALUE]

//>> SET_[CPMS_DPPR_PP0_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PP0_THRESH_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PP0_THRESH_VALUE,
           CPMS_DPPR_PP0_THRESH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_PP0_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PP0_THRESH_VALUE]

//>> GET_[CPMS_DPPR_PP0_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PP0_THRESH_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_PP0_THRESH_VALUE,
           CPMS_DPPR_PP0_THRESH_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_PP0_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PP0_THRESH_VALUE]

//>> SET_[CPMS_DPPR_PP1_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PP1_THRESH_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PP1_THRESH_SCALE,
           CPMS_DPPR_PP1_THRESH_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_PP1_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PP1_THRESH_SCALE]

//>> SET_[CPMS_DPPR_PP1_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PP1_THRESH_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PP1_THRESH_SCALE,
           CPMS_DPPR_PP1_THRESH_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_PP1_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PP1_THRESH_SCALE]

//>> GET_[CPMS_DPPR_PP1_THRESH_SCALE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PP1_THRESH_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_PP1_THRESH_SCALE,
           CPMS_DPPR_PP1_THRESH_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_PP1_THRESH_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PP1_THRESH_SCALE]

//>> SET_[CPMS_DPPR_PP1_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PP1_THRESH_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PP1_THRESH_VALUE,
           CPMS_DPPR_PP1_THRESH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_PP1_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PP1_THRESH_VALUE]

//>> SET_[CPMS_DPPR_PP1_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_PP1_THRESH_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_PP1_THRESH_VALUE,
           CPMS_DPPR_PP1_THRESH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_PP1_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_PP1_THRESH_VALUE]

//>> GET_[CPMS_DPPR_PP1_THRESH_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_PP1_THRESH_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_PP1_THRESH_VALUE,
           CPMS_DPPR_PP1_THRESH_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_PP1_THRESH_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_PP1_THRESH_VALUE]

//>> SET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_WAIT_FOR_GRANT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]

//>> SET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_WAIT_FOR_GRANT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]

//>> SET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_WAIT_FOR_GRANT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]

//>> CLEAR_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_WAIT_FOR_GRANT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]

//>> GET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_WAIT_FOR_GRANT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]

//>> GET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]
static inline bool GET_CPMS_DPPR_OCP_WAIT_FOR_GRANT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_WAIT_FOR_GRANT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_OCP_WAIT_FOR_GRANT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_WAIT_FOR_GRANT]

//>> SET_[CPMS_DPPR_OCP_LOCAL_MSB_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_MSB_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_MSB_MAX,
           CPMS_DPPR_OCP_LOCAL_MSB_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_MSB_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_LOCAL_MSB_MAX]

//>> SET_[CPMS_DPPR_OCP_LOCAL_MSB_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_MSB_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_MSB_MAX,
           CPMS_DPPR_OCP_LOCAL_MSB_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_MSB_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_LOCAL_MSB_MAX]

//>> GET_[CPMS_DPPR_OCP_LOCAL_MSB_MAX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_LOCAL_MSB_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_LOCAL_MSB_MAX,
           CPMS_DPPR_OCP_LOCAL_MSB_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_MSB_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_LOCAL_MSB_MAX]

//>> SET_[CPMS_DPPR_OCP_LOCAL_OVERAGE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_OVERAGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_OVERAGE,
           CPMS_DPPR_OCP_LOCAL_OVERAGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_OVERAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_LOCAL_OVERAGE]

//>> SET_[CPMS_DPPR_OCP_LOCAL_OVERAGE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_OVERAGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_OVERAGE,
           CPMS_DPPR_OCP_LOCAL_OVERAGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_OVERAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_LOCAL_OVERAGE]

//>> GET_[CPMS_DPPR_OCP_LOCAL_OVERAGE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_LOCAL_OVERAGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_LOCAL_OVERAGE,
           CPMS_DPPR_OCP_LOCAL_OVERAGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_OVERAGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_LOCAL_OVERAGE]

//>> SET_[CPMS_DPPR_OCP_LOCAL_TANK_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_TANK_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_TANK_VALUE,
           CPMS_DPPR_OCP_LOCAL_TANK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_TANK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_LOCAL_TANK_VALUE]

//>> SET_[CPMS_DPPR_OCP_LOCAL_TANK_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_LOCAL_TANK_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_LOCAL_TANK_VALUE,
           CPMS_DPPR_OCP_LOCAL_TANK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_TANK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_LOCAL_TANK_VALUE]

//>> GET_[CPMS_DPPR_OCP_LOCAL_TANK_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_LOCAL_TANK_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_LOCAL_TANK_VALUE,
           CPMS_DPPR_OCP_LOCAL_TANK_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_LOCAL_TANK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_LOCAL_TANK_VALUE]

//>> SET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_PITCH_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]

//>> SET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_PITCH_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_PITCH_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]

//>> SET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_PITCH_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]

//>> CLEAR_[CPMS_DPPR_OCP_PITCH_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_PITCH_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_OCP_PITCH_OVERRIDE]

//>> GET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_PITCH_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]

//>> GET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]
static inline bool GET_CPMS_DPPR_OCP_PITCH_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_PITCH_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_OCP_PITCH_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_PITCH_OVERRIDE]

//>> SET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_OVERRIDE_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]

//>> SET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_DPPR_OCP_OVERRIDE_HISTORY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]

//>> SET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.setBit<CPMS_DPPR_OCP_OVERRIDE_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]

//>> CLEAR_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return o_data.clearBit<CPMS_DPPR_OCP_OVERRIDE_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]

//>> GET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_DPPR_OCP_OVERRIDE_HISTORY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]

//>> GET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]
static inline bool GET_CPMS_DPPR_OCP_OVERRIDE_HISTORY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPPR, CPMS_DPPR_WO_CLEAR, CPMS_DPPR_WO_OR));
#endif
    return i_data.getBit<CPMS_DPPR_OCP_OVERRIDE_HISTORY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPPR_OCP_OVERRIDE_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPPR_OCP_OVERRIDE_HISTORY]

//>> PREP_[CPMS_MMA_PFETCNTL]
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
//<< PREP_[CPMS_MMA_PFETCNTL]

//>> GET_[CPMS_MMA_PFETCNTL]
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
//<< GET_[CPMS_MMA_PFETCNTL]

//>> PUT_[CPMS_MMA_PFETCNTL]
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
//<< PUT_[CPMS_MMA_PFETCNTL]

//>> PREP_[CPMS_MMA_PFETCNTL_WO_CLEAR]
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
//<< PREP_[CPMS_MMA_PFETCNTL_WO_CLEAR]

//>> GET_[CPMS_MMA_PFETCNTL_WO_CLEAR]
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
//<< GET_[CPMS_MMA_PFETCNTL_WO_CLEAR]

//>> PUT_[CPMS_MMA_PFETCNTL_WO_CLEAR]
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
//<< PUT_[CPMS_MMA_PFETCNTL_WO_CLEAR]

//>> PREP_[CPMS_MMA_PFETCNTL_WO_OR]
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
//<< PREP_[CPMS_MMA_PFETCNTL_WO_OR]

//>> GET_[CPMS_MMA_PFETCNTL_WO_OR]
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
//<< GET_[CPMS_MMA_PFETCNTL_WO_OR]

//>> PUT_[CPMS_MMA_PFETCNTL_WO_OR]
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
//<< PUT_[CPMS_MMA_PFETCNTL_WO_OR]


//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> CLEAR_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline bool GET_CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> CLEAR_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline bool GET_CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PG_STATE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PG_STATE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PG_STATE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PG_STATE]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PG_STATE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PG_STATE]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PG_SEL]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PG_SEL]

//>> SET_[CPMS_MMA_PFETCNTL_VDD_PG_SEL]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_VDD_PG_SEL]

//>> GET_[CPMS_MMA_PFETCNTL_VDD_PG_SEL]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_VDD_PG_SEL]

//>> SET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]

//>> SET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]

//>> SET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]
static inline fapi2::buffer<uint64_t>& SET_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]

//>> CLEAR_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]

//>> GET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]

//>> GET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]
static inline bool GET_CPMS_MMA_PFETCNTL_MMA_FORCE_CL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_MMA_PFETCNTL, CPMS_MMA_PFETCNTL_WO_CLEAR, CPMS_MMA_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_MMA_PFETCNTL_MMA_FORCE_CL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_MMA_PFETCNTL_MMA_FORCE_CL2]

//>> PREP_[EC_PC_FIR_CORE_RW]
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
//<< PREP_[EC_PC_FIR_CORE_RW]

//>> GET_[EC_PC_FIR_CORE_RW]
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
//<< GET_[EC_PC_FIR_CORE_RW]

//>> PUT_[EC_PC_FIR_CORE_RW]
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
//<< PUT_[EC_PC_FIR_CORE_RW]

//>> PREP_[EC_PC_FIR_CORE_WO_AND]
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
//<< PREP_[EC_PC_FIR_CORE_WO_AND]

//>> GET_[EC_PC_FIR_CORE_WO_AND]
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
//<< GET_[EC_PC_FIR_CORE_WO_AND]

//>> PUT_[EC_PC_FIR_CORE_WO_AND]
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
//<< PUT_[EC_PC_FIR_CORE_WO_AND]

//>> PREP_[EC_PC_FIR_CORE_WO_OR]
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
//<< PREP_[EC_PC_FIR_CORE_WO_OR]

//>> GET_[EC_PC_FIR_CORE_WO_OR]
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
//<< GET_[EC_PC_FIR_CORE_WO_OR]

//>> PUT_[EC_PC_FIR_CORE_WO_OR]
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
//<< PUT_[EC_PC_FIR_CORE_WO_OR]


//>> SET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]

//>> SET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]

//>> SET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]

//>> CLEAR_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]

//>> GET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]

//>> GET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]
static inline bool GET_EC_PC_FIR_CORE_VS_VSMM_ACC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_VS_VSMM_ACC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_VS_VSMM_ACC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_VS_VSMM_ACC_ERR]

//>> SET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_STF_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_STF_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_STF_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_VS_STF_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_VS_STF_ERROR]
static inline bool GET_EC_PC_FIR_CORE_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline bool GET_EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]
static inline bool GET_EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]
static inline bool GET_EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]

//>> CLEAR_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]
static inline bool GET_EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_RW, EC_PC_FIR_CORE_WO_AND, EC_PC_FIR_CORE_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR]

//>> PREP_[EC_PC_FIR_CORE_FIRMASK_RW]
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
//<< PREP_[EC_PC_FIR_CORE_FIRMASK_RW]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_RW]
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
//<< GET_[EC_PC_FIR_CORE_FIRMASK_RW]

//>> PUT_[EC_PC_FIR_CORE_FIRMASK_RW]
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
//<< PUT_[EC_PC_FIR_CORE_FIRMASK_RW]

//>> PREP_[EC_PC_FIR_CORE_FIRMASK_WO_AND]
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
//<< PREP_[EC_PC_FIR_CORE_FIRMASK_WO_AND]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_WO_AND]
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
//<< GET_[EC_PC_FIR_CORE_FIRMASK_WO_AND]

//>> PUT_[EC_PC_FIR_CORE_FIRMASK_WO_AND]
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
//<< PUT_[EC_PC_FIR_CORE_FIRMASK_WO_AND]

//>> PREP_[EC_PC_FIR_CORE_FIRMASK_WO_OR]
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
//<< PREP_[EC_PC_FIR_CORE_FIRMASK_WO_OR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_WO_OR]
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
//<< GET_[EC_PC_FIR_CORE_FIRMASK_WO_OR]

//>> PUT_[EC_PC_FIR_CORE_FIRMASK_WO_OR]
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
//<< PUT_[EC_PC_FIR_CORE_FIRMASK_WO_OR]


//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_FIRMASK_RW, EC_PC_FIR_CORE_FIRMASK_WO_AND, EC_PC_FIR_CORE_FIRMASK_WO_OR));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR]

//>> PREP_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS]
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
//<< PREP_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS]
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
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS]

//>> PUT_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS]
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
//<< PUT_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS]


//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]
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
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]
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
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]

//>> SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]

//>> CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]
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
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]

//>> GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]
static inline bool GET_EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP]

//>> PREP_[L2_L2MISC_L2CERRS_FIR_MASK_REG_RW]
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
//<< PREP_[L2_L2MISC_L2CERRS_FIR_MASK_REG_RW]

//>> GET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_RW]
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
//<< GET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_RW]

//>> PUT_[L2_L2MISC_L2CERRS_FIR_MASK_REG_RW]
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
//<< PUT_[L2_L2MISC_L2CERRS_FIR_MASK_REG_RW]

//>> PREP_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND]
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
//<< PREP_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND]

//>> GET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND]
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
//<< GET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND]

//>> PUT_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND]
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
//<< PUT_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND]

//>> PREP_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR]
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
//<< PREP_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR]

//>> GET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR]
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
//<< GET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR]

//>> PUT_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR]
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
//<< PUT_[L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR]


//>> SET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK]
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
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK]

//>> SET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK]
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
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK]

//>> GET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK]
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
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
