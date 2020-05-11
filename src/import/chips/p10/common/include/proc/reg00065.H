/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00065.H $         */
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

#ifndef __PROC_REG00065_H_
#define __PROC_REG00065_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR]

//>> GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR]

//>> PUT_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR]


//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR]

//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR]

//>> GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR]

//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]

//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]

//>> SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return o_data.setBit<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]

//>> CLEAR_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return o_data.clearBit<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]

//>> GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]

//>> GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]
static inline bool GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR));
#endif
    return i_data.getBit<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE]

//>> PREP_[NX_PBI_RNG_ST3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_ST3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_RNG_ST3]

//>> GET_[NX_PBI_RNG_ST3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_ST3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST3;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_ST3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_RNG_ST3]

//>> PUT_[NX_PBI_RNG_ST3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_ST3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_ST3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_RNG_ST3]


//>> SET_[NX_PBI_RNG_ST3_RRN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_RRN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_RRN_ENABLE]

//>> SET_[NX_PBI_RNG_ST3_RRN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_RRN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_RRN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_RRN_ENABLE]

//>> SET_[NX_PBI_RNG_ST3_RRN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.setBit<NX_PBI_RNG_ST3_RRN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_RRN_ENABLE]

//>> CLEAR_[NX_PBI_RNG_ST3_RRN_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.clearBit<NX_PBI_RNG_ST3_RRN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_ST3_RRN_ENABLE]

//>> GET_[NX_PBI_RNG_ST3_RRN_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST3_RRN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST3_RRN_ENABLE]

//>> GET_[NX_PBI_RNG_ST3_RRN_ENABLE]
static inline bool GET_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return i_data.getBit<NX_PBI_RNG_ST3_RRN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST3_RRN_ENABLE]

//>> SET_[NX_PBI_RNG_ST3_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_WINDOW_SIZE,
           NX_PBI_RNG_ST3_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST3_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_WINDOW_SIZE]

//>> SET_[NX_PBI_RNG_ST3_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_WINDOW_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_WINDOW_SIZE,
           NX_PBI_RNG_ST3_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST3_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_WINDOW_SIZE]

//>> GET_[NX_PBI_RNG_ST3_WINDOW_SIZE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST3_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST3_WINDOW_SIZE,
           NX_PBI_RNG_ST3_WINDOW_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST3_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST3_WINDOW_SIZE]

//>> SET_[NX_PBI_RNG_ST3_MATCH_TH_MIN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_MATCH_TH_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_MATCH_TH_MIN,
           NX_PBI_RNG_ST3_MATCH_TH_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_MATCH_TH_MIN]

//>> SET_[NX_PBI_RNG_ST3_MATCH_TH_MIN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_MATCH_TH_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_MATCH_TH_MIN,
           NX_PBI_RNG_ST3_MATCH_TH_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_MATCH_TH_MIN]

//>> GET_[NX_PBI_RNG_ST3_MATCH_TH_MIN]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST3_MATCH_TH_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST3_MATCH_TH_MIN,
           NX_PBI_RNG_ST3_MATCH_TH_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST3_MATCH_TH_MIN]

//>> SET_[NX_PBI_RNG_ST3_MATCH_TH_MAX]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_MATCH_TH_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_MATCH_TH_MAX,
           NX_PBI_RNG_ST3_MATCH_TH_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_MATCH_TH_MAX]

//>> SET_[NX_PBI_RNG_ST3_MATCH_TH_MAX]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_MATCH_TH_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_MATCH_TH_MAX,
           NX_PBI_RNG_ST3_MATCH_TH_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST3_MATCH_TH_MAX]

//>> GET_[NX_PBI_RNG_ST3_MATCH_TH_MAX]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST3_MATCH_TH_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST3));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST3_MATCH_TH_MAX,
           NX_PBI_RNG_ST3_MATCH_TH_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST3_MATCH_TH_MAX]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG]

//>> GET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG]


//>> SET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0,
           PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0,
           PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0,
           PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION0_REG_PB_STATION_FIR_ACTION0]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG]

//>> GET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG]


//>> SET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1,
           PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1]

//>> SET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1,
           PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1]

//>> GET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1,
           PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_FIR_ACTION1_REG_PB_STATION_FIR_ACTION1]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3,
           PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
