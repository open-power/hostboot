/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00034.H $         */
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

#ifndef __PROC_REG00034_H_
#define __PROC_REG00034_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_CR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_CR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_FRAME_SIZE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_OUT_COUNT2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_DELAY2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR0_IN_COUNT2]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_11A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_18A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_19A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_32A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_33A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_34A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_35A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_38A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_39A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_42A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_43A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RESERVED_55A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_FREE_USAGE_63A]

//>> PREP_[TP_TPCHIP_TPC_OPCG_ALIGN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_OPCG_ALIGN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_OPCG_ALIGN]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_OPCG_ALIGN;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_OPCG_ALIGN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN]

//>> PUT_[TP_TPCHIP_TPC_OPCG_ALIGN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_OPCG_ALIGN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_OPCG_ALIGN]


//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_ALIGN]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_ALIGN]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN,
           TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_ALIGN]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_WAIT]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_WAIT]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT,
           TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_WAIT]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]

//>> CLEAR_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]
static inline bool GET_TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_INOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]

//>> CLEAR_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]
static inline bool GET_TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SNOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]

//>> CLEAR_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]
static inline bool GET_TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ENOP_FORCE_SG]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> CLEAR_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]
static inline bool GET_TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_ALIGN_SOURCE_SELECT]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO,
           TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO,
           TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO,
           TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_SCAN_RATIO]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES]

//>> SET_[TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES]

//>> GET_[TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_OPCG_ALIGN_OPCG_WAIT_CYCLES]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL0_RW]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL0_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_RW]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL0_RW]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL0_RW, TP_TPCHIP_TPC_CPLT_CTRL0_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL0_WO_OR]


//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0]


//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0,
           TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0,
           TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0,
           TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
